#!/bin/bash
set -e

DB_DATA_DIR="/var/lib/mysql"
DB_SOCKET_DIR="/run/mysqld"

DB_PASSWORD="$(cat "${DB_PASSWORD_FILE}")"
DB_ROOT_PASSWORD="$(cat "${DB_ROOT_PASSWORD_FILE}")"

mkdir -p "$DB_DATA_DIR"
mkdir -p "$DB_SOCKET_DIR"

chown -R mysql:mysql "$DB_DATA_DIR"
chown -R mysql:mysql "$DB_SOCKET_DIR"

cd "$DB_DATA_DIR"

if [ ! -d "$DB_DATA_DIR/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --datadir="$DB_DATA_DIR"

    echo "Starting temporary MariaDB..."
    mariadbd --user=mysql \
        --datadir="$DB_DATA_DIR" \
        --socket="$DB_SOCKET_DIR/mysqld.sock" \
        --bind-address=127.0.0.1 &

    echo "Waiting for MariaDB to be ready..."
    until mariadb-admin --socket="$DB_SOCKET_DIR/mysqld.sock" ping --silent; do
        sleep 1
    done

    echo "Configuring database and user..."

    mariadb --socket="$DB_SOCKET_DIR/mysqld.sock" <<EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db LIKE 'test\\_%';
DELETE FROM mysql.user WHERE User='';

FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
EOF

    echo "Stopping temporary MariaDB..."
    mariadb-admin --socket="$DB_SOCKET_DIR/mysqld.sock" \
        -u root \
        -p"${DB_ROOT_PASSWORD}" \
        shutdown
fi

echo "Starting MariaDB in foreground..."
exec mariadbd --user=mysql \
    --datadir="$DB_DATA_DIR" \
    --socket="$DB_SOCKET_DIR/mysqld.sock" \
    --bind-address=0.0.0.0