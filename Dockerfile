FROM gcc:13 AS builder

WORKDIR /app

COPY . .

RUN gcc -static -O2 main.c tasks.c -o devlog


FROM scratch

WORKDIR /app

COPY --from=builder /app/devlog .

ENTRYPOINT ["./devlog"]