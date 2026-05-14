#!/bin/bash
set -e

DB_DATA_DIR="/var/lib/mysql"
DB_PASSWORD="$(cat "${DB_PASSWORD_FILE}")"
DB_ROOT_PASSWORD="$(cat "${DB_ROOT_PASSWORD_FILE}")"

if [ ! -d "$DB_DATA_DIR/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --datadir="$DB_DATA_DIR"

    echo "Starting temporary MariaDB..."
    mysqld_safe --datadir="$DB_DATA_DIR" &

    echo "Waiting for MariaDB to be ready..."
    until mariadb-admin ping --silent; do
        sleep 1
    done

    echo "Configuring database and user..."
    mariadb -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
    mariadb -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
    mariadb -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';"
    mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
    mariadb -e "FLUSH PRIVILEGES;"

    echo "Stopping temporary MariaDB..."
    mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown

fi

echo "Starting MariaDB in foreground..."
exec mysqld_safe --datadir="$DB_DATA_DIR"