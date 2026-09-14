#!/bin/bash
set -e

: "${DOMAIN_NAME:?DOMAIN_NAME is not set}"
: "${MYSQL_DATABASE:?MYSQL_DATABASE is not set}"
: "${MYSQL_USER:?MYSQL_USER is not set}"
: "${DB_HOST:?DB_HOST is not set}"
: "${DB_PASSWORD_FILE:?DB_PASSWORD_FILE is not set}"

: "${WP_TITLE:?WP_TITLE is not set}"
: "${WP_ADMIN_USER:?WP_ADMIN_USER is not set}"
: "${WP_ADMIN_EMAIL:?WP_ADMIN_EMAIL is not set}"
: "${WP_ADMIN_PASSWORD_FILE:?WP_ADMIN_PASSWORD_FILE is not set}"

: "${WP_USER:?WP_USER is not set}"
: "${WP_USER_EMAIL:?WP_USER_EMAIL is not set}"
: "${WP_USER_PASSWORD_FILE:?WP_USER_PASSWORD_FILE is not set}"

WP_PATH="/var/www/html"

DB_PASSWORD="$(cat "${DB_PASSWORD_FILE}")"
WP_ADMIN_PASSWORD="$(cat "${WP_ADMIN_PASSWORD_FILE}")"
WP_USER_PASSWORD="$(cat "${WP_USER_PASSWORD_FILE}")"

mkdir -p "${WP_PATH}"

echo "Waiting for MariaDB..."
until mariadb -h "${DB_HOST}" \
    -u "${MYSQL_USER}" \
    -p"${DB_PASSWORD}" \
    "${MYSQL_DATABASE}" \
    -e "SELECT 1;" >/dev/null 2>&1; do
    sleep 1
done

echo "MariaDB is ready."

if [ ! -x /usr/local/bin/wp ]; then
    echo "Installing wp-cli..."
    curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
        -o /usr/local/bin/wp
    chmod +x /usr/local/bin/wp
fi

if [ ! -f "${WP_PATH}/wp-load.php" ]; then
    echo "Downloading WordPress..."
    wp core download \
        --path="${WP_PATH}" \
        --allow-root
fi

if [ ! -f "${WP_PATH}/wp-config.php" ]; then
    echo "Creating wp-config.php..."
    wp config create \
        --path="${WP_PATH}" \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --dbhost="${DB_HOST}" \
        --skip-check \
        --allow-root
fi

if ! wp core is-installed --path="${WP_PATH}" --allow-root; then
    echo "Installing WordPress..."
    wp core install \
        --path="${WP_PATH}" \
        --url="https://${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root
fi

if ! wp user get "${WP_USER}" --path="${WP_PATH}" --allow-root >/dev/null 2>&1; then
    echo "Creating WordPress normal user..."
    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --path="${WP_PATH}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author \
        --allow-root
fi

chown -R www-data:www-data "${WP_PATH}"

echo "Starting php-fpm..."
exec php-fpm8.2 -F