#include <stdint.h>
#include <stdio.h>

void delay();

int main()
{

    uint32_t volatile *RCC = (uint32_t *)(0x40021000 + 0x34);
    uint32_t volatile *MODER_A = (uint32_t *)(0x50000000);
    uint32_t volatile *MODER_B = (uint32_t *)(0x50000400);
    uint32_t volatile *ODR_A = (uint32_t *)(0x50000000 + 0x14);
    uint32_t volatile *IDR_B = (uint32_t *)(0x50000400 + 0x10);
    uint32_t volatile *PUPDR_B = (uint32_t *)(0x50000400 + 0x0C);

    // clock enable
    *RCC &= ~(3 << 0);
    *RCC |= (3 << 0);

    // configuring output A 
    *MODER_A &= ~(0xFF << 8);
    *MODER_A |= (0x55 << 8);

    // configuring input B
    *MODER_B &= ~(0xFF << 22);
    

    // making PA4 PA5 PA6 PA7 as HIGH
    *ODR_A &= ~(0xF << 4);
    *ODR_A |= (0xF << 4);

    // adding pull up
    *PUPDR_B &= ~(0xFF << 22);
    *PUPDR_B |= (0x55 << 22);





    while (1)
    {
        // making PA4 low
        *ODR_A &= ~(1 << 4);


        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("1\n");
        }
        if (!((*IDR_B >> 12) & 0x1))
        {
            delay();
            printf("2\n");
        }
        if (!((*IDR_B >> 13) & 0x1))
        {
            delay();
            printf("3\n");
        }
        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("A\n");
        }

        *ODR_A |= (0xF << 4);
        // making PA5 low
        *ODR_A &= ~(1 << 5);

        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("4\n");
        }
        if (!((*IDR_B >> 12) & 0x1))
        {
            delay();
            printf("5\n");
        }
        if (!((*IDR_B >> 13) & 0x1))
        {
            delay();
            printf("6\n");
        }
        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("B\n");
        }


        *ODR_A |= (0xF << 4);
        // making PA6 low
        *ODR_A &= ~(1 << 6);

        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("7\n");
        }
        if (!((*IDR_B >> 12) & 0x1))
        {
            delay();
            printf("8\n");
        }
        if (!((*IDR_B >> 13) & 0x1))
        {
            delay();
            printf("9\n");
        }
        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("C\n");
        }


        *ODR_A |= (0xF << 4);
        // making PA7 low
        *ODR_A &= ~(1 << 7);

        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("*\n");
        }
        if (!((*IDR_B >> 12) & 0x1))
        {
            delay();
            printf("0\n");
        }
        if (!((*IDR_B >> 13) & 0x1))
        {
            delay();
            printf("#\n");
        }
        if (!((*IDR_B >> 11) & 0x1))
        {
            delay();
            printf("D\n");
        }
    }

    return 0;
}
void delay()
{

    for (volatile uint32_t i = 0; i < 300000; i++);
  
    

}