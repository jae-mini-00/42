FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    dumb-init \
    && rm -rf /var/lib/mysql/* \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./tools/init.sh /init.sh

RUN chmod +x /init.sh

EXPOSE 3306

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]
CMD [ "/init.sh" ]