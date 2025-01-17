#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"

// Definir variáveis do LED RGB
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

// Definir variáveis do teclado matricial
int linha[4] = {8, 7, 6, 5};
int coluna[4] = {4, 3, 2, 28};

char teclado[4][4] = {{'1', '2', '3', 'A'},
                      {'4', '5', '6', 'B'},
                      {'7', '8', '9', 'C'},
                      {'*', '0', '#', 'D'}};

// Definir variáveis do Buzzer 

// Frequência de operação do Buzzer (Hz)
#define BUZZER_FREQUENCY 100
// Pino Buzzer GPIO 21
#define BUZZER_PIN 21

/*Essa função inicializa os pinos GPIO do teclado matricial e
Ativa resistores pull-down nos pinos de entrada para evitar leituras flutuantes */
void pinoMatricial()
{
    for (int i = 0; i < 4; i++)
    {
        gpio_init(linha[i]);
        gpio_set_dir(linha[i], GPIO_OUT);
        gpio_put(linha[i], 0);
    }

    for (int j = 0; j < 4; j++)
    {
        gpio_init(coluna[j]);
        gpio_set_dir(coluna[j], GPIO_IN);
        gpio_pull_down(coluna[j]);
    }
}

// Essa função verifica o teclado matricial para detectar qual tecla foi pressionada.
char teclaPressionada()
{
    for (int i = 0; i < 4; i++)
    {
        gpio_put(linha[i], 1);

        for (int j = 0; j < 4; j++)
        {
            if (gpio_get(coluna[j]))
            {
                gpio_put(linha[i], 0);
                return teclado[i][j];
            }
        }

        gpio_put(linha[i], 0);
    }
    return '\0';
}

// Função para ligar o LED RGB
void turn_on_led(int red_pin, int green_pin, int blue_pin, int red, int green, int blue)
{
    gpio_put(red_pin, red);
    gpio_put(green_pin, green);
    gpio_put(blue_pin, blue);
}
// Função recebe o caractere correspondente à tecla pressionada e realiza uma ação associada.
void read_keypad(char tecla)
{

    switch (tecla)
    {

    case '0':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 0, 0, 0);
        sleep_ms(200);
        break;

    case '1':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 1, 0, 0);
        sleep_ms(200);
        break;

    case '2':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 0, 1, 0);
        sleep_ms(200);
        break;

    case '3':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 0, 0, 1);
        sleep_ms(200);
        break;

    case '4':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 1, 1, 0);
        sleep_ms(200);
        break;

    case '5':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 1, 0, 1);
        sleep_ms(200);
        break;

    case '6':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 0, 1, 1);
        sleep_ms(200);
        break;
    case '7':
        printf("Tecla pressionada: %c\n", tecla);
        turn_on_led(LED_RED, LED_GREEN, LED_BLUE, 1, 1, 1);
        sleep_ms(200);
        break;

    case '8':
        printf("Tecla pressionada: %c\n", tecla);
        sleep_ms(200);
        break;

    case '9':
        printf("Tecla pressionada: %c\n", tecla);
        sleep_ms(200);
        break;

    case 'A':
        // Implementar função correspondente
        break;

    case 'B':
        // Implementar função correspondente
        break;

    case 'C':
        // Implementar função correspondente
        break;

    case 'D':
        // Implementar função correspondente
        break;

    case '#':
        play_buzzer(BUZZER_PIN, BUZZER_FREQUENCY, 500); // Bipe do buzzer de 500ms
        break;

    case '*':
        // Implementar função correspondente
        break;

    default:
        printf("Tecla não reconhecida ou erro na operação!\n");
        break;
    }
}

// Função para tocar o Buzzer
void play_buzzer(uint gpio, uint freq, uint duration_ms) {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM); // Configura o pino como PWM
    
    // Slice PWM do pino
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Configuração do PWM
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f); // Definindo o divisor de clock
    pwm_init(slice_num, &config, true);

    // Frequência do PWM pela BUZZER_FREQUENCY
    uint clock_freq = clock_get_hz(clk_sys); // Frequência do clock 
    float clkdiv = 4.0f; // Divisor do clock
    uint top = clock_freq / (freq * clkdiv); // Cálculo do TOP 

    pwm_set_wrap(slice_num, top); 
    pwm_set_gpio_level(BUZZER_PIN, top / 2); 

    // Duração do som emitido
    sleep_ms(duration_ms);

    // Desliga o Buzzer
    pwm_set_gpio_level(BUZZER_PIN, 0);
    
    sleep_ms(100); // Entrepausa de 100ms
}

int main()
{
    char key;

    // Inicializar GPIOs do LED RGB
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    pinoMatricial(); // chama a função do GPIO do teclado matricial

    // Inicializar GPIOs do Buzzer

    stdio_init_all();

    while (true)
    {
        // Ler tecla pressionada
        key = teclaPressionada();

        if (key != '\0')
        {
            read_keypad(key);
        }

        // Ligar LED RGB de acordo com a tecla pressionada

        // Tocar buzzer com frequência e duração de acordo com a tecla pressionada
    }
}

void play_buzzer(freq, duration)
{
    // Implementar função para tocar o buzzer
}
