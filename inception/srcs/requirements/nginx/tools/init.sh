#!/bin/bash
set -e

: "${DOMAIN_NAME:?DOMAIN_NAME is not set}"

SSL_DIR="/etc/nginx/ssl"
CERT_FILE="$SSL_DIR/nginx.crt"
KEY_FILE="$SSL_DIR/nginx.key"

mkdir -p "$SSL_DIR"

if [ ! -f "$CERT_FILE" ] || [ ! -f "$KEY_FILE" ]; then
    echo "Generating TLS certificate..."

    openssl req \
        -x509 \
        -nodes \
        -newkey rsa:2048 \
        -days 365 \
        -keyout "$KEY_FILE" \
        -out "$CERT_FILE" \
        -subj "/C=KR/O=42/OU=Inception/CN=${DOMAIN_NAME}"
fi

chmod 600 "$KEY_FILE"
chmod 644 "$CERT_FILE"

echo "Checking Nginx configuration..."
nginx -t

echo "Starting Nginx..."
exec nginx -g "daemon off;"
