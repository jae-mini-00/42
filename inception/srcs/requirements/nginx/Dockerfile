FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    dumb-init \
    && rm -rf /etc/nginx/sites-enabled/default \
    && rm -rf /etc/nginx/sites-available/default \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/init.sh /init.sh

RUN chmod +x /init.sh

EXPOSE 443

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["/init.sh"]