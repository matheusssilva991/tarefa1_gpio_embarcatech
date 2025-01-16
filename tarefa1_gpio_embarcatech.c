#include <stdio.h>
#include "pico/stdlib.h"

// Definir variáveis do LED RGB

// Definir variáveis do teclado matricial

// Definir variáveis do Buzzer

// Função para ler o teclado matricial e retornar a tecla pressionada
char read_keypad();

// Função para tocar o buzzer
void play_buzzer(freq, duration);

// Função para ligar o LED RGB
void turn_on_led(int gpio);

int main() {
    char key;

    // Inicializar GPIOs do LED RGB

    // Inicializar GPIOs do teclado matricial

    // Inicializar GPIOs do Buzzer

    stdio_init_all();

    while (true) {
        // Ler tecla pressionada
        key = read_keypad();

        // Ligar LED RGB de acordo com a tecla pressionada

        // Tocar buzzer com frequência e duração de acordo com a tecla pressionada
    }
}

char read_keypad() {
    // Implementar leitura do teclado matricial
    return ' ';
}

void play_buzzer(freq, duration) {
    // Implementar função para tocar o buzzer
}

void turn_on_led(int gpio) {
    // Implementar função para ligar o LED RGB
};
