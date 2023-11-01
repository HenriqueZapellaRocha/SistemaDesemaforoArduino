#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    // seta os pinos de saida
    DDRB |= (1 << PB5) | (1 << PB4) | (1 << PB3) | (1 << PB2) | (1 << PB1) | (1 << PB0) | (1 << PB6);
    // seta o pino de entrada
    DDRD &= ~(1 << PD6); // Define o PD6 como entrada para o botão de pedestres

    // para saber se o botao fois pressionado
    int estado = 0;

    while(1) {
        // Se o botão de pedestres for pressionado, caso ele tenha sido pressionado e executado o trecho de codigo que corresponde ao botao presisado.
        if (PIND & (1 << PD6)) {
            estado = 1;
        }

        // caso o botao tenha sido pressioando 
           if(estado == 1) {
            // acontece a sequencia padrao de execucao dos farois, porem com a luz verde do pedestre liagada 
            PORTB = (1 << PB5) | (1 << PB0) | (1 << PB6);
            _delay_ms(3000);
            PORTB = (1 << PB4) | (1 << PB0) | (1 << PB6);
            _delay_ms(1000);
            estado = 0;
            // deixa as luzes vermelhas do semaforo ligadas
            PORTB = (1 << PB0) | (1 << PB3);
            // luz dos pedestres pisca, autorizando sua passagem 
            for (int i = 0; i < 3; ++i) {
                PORTB |= (1 << PB6); // Liga o LED
                _delay_ms(500); // Fica ligado por 500ms
                PORTB &= ~(1 << PB6); // Desliga o LED
                _delay_ms(500); // Fica desligado por 500ms
            }
            // luz de pedestre fica ligada por 1 segundo e depois segue a execuco normal dos semaofors 
            PORTB = (1 << PB6) | (1 << PB0) | (1 << PB3);
            _delay_ms(1000);

            // caso o botao nao tenha sido pressionado, segue a execucao comum do semaforo 
           } else if(estado == 0) {
            PORTB = (1 << PB5) | (1 << PB0);
            _delay_ms(3000);
            PORTB = (1 << PB4) | (1 << PB0);
            _delay_ms(1000);

           }

            if (PIND & (1 << PD6)) {
            estado = 1;
        }
             // caso o botao tenha sido pressioando 
            if(estado == 1) {
            // acontece a sequencia padrao de execucao dos farois, porem com a luz verde do pedestre liagada 
            PORTB = (1 << PB2) | (1 << PB3) | (1 << PB6);
            _delay_ms(3000);
            PORTB = (1 << PB1) | (1 << PB3) | (1 << PB6);
            _delay_ms(1000);
            estado = 0;
             // deixa as luzes vermelhas do semaforo ligadas
            PORTB = (1 << PB0) | (1 << PB3);
            // luz dos pedestres pisca, autorizando sua passagem 
            for (int i = 0; i < 3; ++i) {
                PORTB |= (1 << PB6); // Liga o LED
                _delay_ms(500); // Fica ligado por 500ms
                PORTB &= ~(1 << PB6); // Desliga o LED
                _delay_ms(500); // Fica desligado por 500ms
            }
            // luz de pedestre fica ligada por 1 segundo e depois segue a execuco normal dos semaofors 
            PORTB = (1 << PB6) | (1 << PB0) | (1 << PB3);
            _delay_ms(1000);
           // caso o botao nao tenha sido pressionado, segue a execucao comum do semaforo 
           } else if(estado == 0) {
            PORTB = (1 << PB2) | (1 << PB3);
            _delay_ms(3000);
            PORTB = (1 << PB1) | (1 << PB3);
            _delay_ms(1000);

           }
      
    }
}

