#include <avr/io.h>
#include "clunet.h"

#define LED_PIN             PB3
#define COMMAND_LED_OFF     0
#define COMMAND_LED_ON      1

/* Main receiving callback function. Executed in user non-interrupt context from clunet_task(). Must be non-static. */
uint8_t
clunet_receive_cb(clunet_message_t *message)
{
    /* ignore all broadcast messages */
    if (message->dst_address == CLUNET_ADDRESS_BROADCAST)
        return CLUNET_CALLBACK_RESULT_NORMAL;

    switch (message->command)
    {
    case COMMAND_LED_OFF:       /* On */
        PORTB &= ~_BV(LED_PIN);
        break;
    case COMMAND_LED_ON:        /* Off */
        PORTB |= _BV(LED_PIN);
        break;
    default:                    /* Inverse */
        /* This op work only on MCUs with PCIRQ. Use PORTB ^= _BV(LED_PIN) instead. */
        PINB = _BV(LED_PIN);
        break;
    }

    return CLUNET_CALLBACK_RESULT_NORMAL;
}

int
main(void)
{
    DDRB |= _BV(LED_PIN);

    clunet_init();

    for ( ; ; )
    {
        clunet_task();
    }
}
