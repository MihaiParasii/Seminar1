FROM gcc:9.5.0-bullseye
WORKDIR /app
COPY /main.c /app/main.c

RUN gcc -o testindocker main.c
CMD ["./testindocker"]