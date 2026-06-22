NAME = inception

COMPOSE_FILE = srcs/docker-compose.yml
ENV_FILE = srcs/.env
COMPOSE = docker compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE)

DATA_DIR = /home/jaejo/data
DB_DATA_DIR = $(DATA_DIR)/wordpress_database
WP_DATA_DIR = $(DATA_DIR)/wordpress_site_data

all: up

up:
	mkdir -p $(DB_DATA_DIR)
	mkdir -p $(WP_DATA_DIR)
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down

start:
	$(COMPOSE) start

stop:
	$(COMPOSE) stop

restart:
	$(COMPOSE) restart

status:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

clean: down
	docker system prune -af

fclean:
	$(COMPOSE) down -v --rmi all --remove-orphans
	sudo rm -rf $(DATA_DIR)
	docker system prune -af

re: fclean all

.PHONY: all up down start stop restart status logs clean fclean re
