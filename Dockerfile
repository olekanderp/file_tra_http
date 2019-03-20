FROM node:8

# Папка приложения
ARG APP_DIR=app_model
RUN mkdir -p ${APP_DIR}
WORKDIR ${APP_DIR}

RUN apt-get update
# Установка зависимостей
COPY package*.json ./
RUN npm install -g nodemon
RUN npm install
# Для использования в продакшне
# RUN npm install --production

RUN apt-get install nano 
# Копирование файлов проекта
COPY . .

# Уведомление о порте, который будет прослушивать работающее приложение
EXPOSE 3000

# Запуск проекта
CMD ["npm", "start"]
