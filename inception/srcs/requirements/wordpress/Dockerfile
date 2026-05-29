FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-cli \
    php-mysql \
    php-curl \
    php-xml \
    php-mbstring \
    php-zip \
    php-gd \
    php-intl \
    curl \
    ca-certificates \
    mariadb-client \
    dumb-init \
    unzip \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./tools/init.sh /init.sh
COPY ./conf/php-fpm.conf /etc/php/8.2/fpm/pool.d/www.conf

RUN chmod +x /init.sh

EXPOSE 9000

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "/init.sh" ]