# Controle de Pinos GPIO com Teclado Matricial

## Descrição do Projeto
Este projeto implementa um sistema de controle de pinos GPIO utilizando um teclado matricial 4x4 em conjunto com o microcontrolador RP2040 na placa Raspberry Pi Pico W. O sistema permite o controle de 3 LEDs RGB e um buzzer através das entradas do teclado matricial, sendo desenvolvido e simulado utilizando a plataforma Wokwi.

## Componentes do Projeto
- Teclado matricial 4x4
- 3 LEDs RGB
- Buzzer
- Raspberry Pi Pico W (microcontrolador RP2040)

## Requisitos
### Software
- Visual Studio Code
- Pico SDK
- Extensão Wokwi para VS Code
- Git
- Compilador C para ARM

### Hardware (para simulação)
- Computador com Windows/Linux/MacOS
- Conexão com a Internet

## Instalação
1. Clone este repositório:
```bash
git clone [https://github.com/matheusssilva991/tarefa1_gpio_embarcatech.git]
```

2. Instale o VS Code através do [Site oficial] https://code.visualstudio.com/download

3. Instale a extensão Wokwi para VS Code

4. Configure o Pico SDK seguindo a [Documentação do Raspberry Pi
Pico] https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

## Como Executar o Projeto

### Configuração do Ambiente
1. No VS Code, instale as seguintes extensões:
   - CMake Tools
   - Wokwi Simulator
   - C/C++

2. Configure o ambiente Pico SDK:
   - Certifique-se de que o PICO_SDK_PATH está configurado corretamente nas variáveis de ambiente
   - Instale o CMake e o compilador GCC para ARM
   - Configure o arquivo CMakeLists.txt com as dependências necessárias

### Compilação e Execução
1. Prepare o projeto:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

2. Compile o projeto:
   ```bash
   make
   ```

3. Simulação no Wokwi:
   - Abra o VS Code
   - Crie/edite o arquivo wokwi.toml
   - Configure o diagram.json com os componentes:
     * Raspberry Pi Pico W
     * Teclado Matricial 4x4
     * 3 LEDs RGB
     * Buzzer
   - Conecte os componentes seguindo o esquema do projeto
   - Carregue o arquivo .uf2 gerado na compilação
   - Clique em "Start Simulation"

### Pinagem do Projeto
- Teclado Matricial:
  * Linhas: GPIOs [especificar pinos]
  * Colunas: GPIOs [especificar pinos]
- LEDs RGB:
  * LED1: GPIOs [especificar pinos]
  * LED2: GPIOs [especificar pinos]
  * LED3: GPIOs [especificar pinos]
- Buzzer: GPIO [especificar pino]

### Funcionamento
- O teclado matricial controla os LEDs RGB e o buzzer
- [Adicionar descrição específica do funcionamento]

## Demonstração
Vídeo demonstrativo do projeto em funcionamento: [Link do Vídeo]

## 📝 Contribuição

Contribuições são sempre bem-vindas! Siga os passos abaixo para participar:

1. **Faça um Fork do Repositório**  
   Clique no botão "Fork" na página do projeto no GitHub.

2. **Crie uma Nova Branch**  
   ```bash
   git checkout -b feature/sua-nova-função
   ```
3. **Implemente as Mudanças**  
   Edite o código e faça commits regularmente.

4. **Envie as Mudanças**  
   ```bash
   git push origin feature/sua-nova-função
   ```

5. **Abra um Pull Request**  
   Descreva suas alterações e aguarde a revisão.

---

Qualquer dúvida ou sugestão, sinta-se à vontade para abrir uma issue ou entrar em contato.

## Membros da Equipe de desenvolvedores
- [nome do desenvolvedor 1] - [Função específica]
- [Nome do Desenvolvedor 2] - [Função específica]
- [Nome do Desenvolvedor 3] - [Função específica]
- [Nome do Desenvolvedor 4] - [Função específica]
- [Nome do Desenvolvedor 5] - [Função específica]
- [Nome do Desenvolvedor 6] - [Função específica]
- [Nome do Desenvolvedor 7] - [Função específica]

## Links Úteis
- [Simulação no Wokwi](https://www.dropbox.com/scl/fi/va5dp18ahzarjyd6z8boh/2025-01-09-16-29-53.mkv?rlkey=j93icbgjf3m080d1tyde33fxz&dl=0)
- [Experimento BitDogLab](https://www.dropbox.com/scl/fi/oakfs3evgysjt6dmtel60/VID-20250109-WA0043.mp4?rlkey=03s40wpvjx5hhjipdoi2q8uky&dl=0)
