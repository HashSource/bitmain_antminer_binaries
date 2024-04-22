#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

uint16_t g_power_type = 1u; // idb
int power_control_fd;       // idb
pthread_mutex_t i2c_mutex;  // idb

bool gHashBoard_BHB07601;  // idb
bool gHashBoard_BHB91603P; // idb
bool gHashBoard_BHB91603S; // idb
bool gHashBoard_BHB91601S; // idb
bool gHashBoard_BHB91601P; // idb

unsigned int BHB91603_ASIC_NUMBER; // idb
unsigned int BHB91601_ASIC_NUMBER; // idb
unsigned int BHB07601_ASIC_NUMBER; // idb

void power_check_type()
{
    int v0; // r4

    pthread_mutex_lock(&i2c_mutex);
    v0 = i2c_read(0x5200000u);
    pthread_mutex_unlock(&i2c_mutex);
    if (v0 == 245)
    {
        puts("power type APW9 3600W");
        g_power_type = 2;
    }
    else
    {
        puts("power type APW8 2000W");
        g_power_type = 1;
    }
}

int open_power_control()
{
    int result; // r0

    power_check_type();
    result = open("/sys/class/gpio/gpio907/value", 2049);
    power_control_fd = result;
    if (result < 0)
    {
        puts("open power control gpio failed!!!");
        return power_control_fd;
    }
    return result;
}

void close_power_control()
{
    close(power_control_fd);
    j_puts("power control gpio closed!!!");
}

void power_on()
{
    j_write(power_control_fd, "0", 1u);
}

void power_off()
{
    j_write(power_control_fd, "1", 1u);
}

bool power_check_reply(uint8_t *cmd, uint8_t *reply_buf, uint8_t reply_len)
{
    int v4;       // r5
    uint8_t *v5;  // r5
    uint8_t *v6;  // r4
    int v7;       // t1
    int v9;       // r0
    int v10;      // r1
    int v11;      // r3
    uint16_t v12; // r2
    int v13;      // r2
    uint8_t *v14; // r5
    uint8_t *v15; // r4
    int v16;      // t1

    v4 = reply_len;
    if (*cmd != *reply_buf || cmd[1] != reply_buf[1] || cmd[3] != reply_buf[3] || (v9 = reply_buf[2], v9 + 2 != reply_len))
    {
        puts("power reply data error:");
        if (v4)
        {
            v5 = &reply_buf[(uint16_t)(v4 - 1)];
            v6 = reply_buf - 1;
            do
            {
                v7 = *++v6;
                printf("%02x ", v7);
            } while (v5 != v6);
        }
        goto LABEL_5;
    }
    if (reply_buf[2] > 2u)
    {
        v11 = 2;
        v10 = 0;
        do
        {
            v12 = reply_buf[v11];
            v11 = (uint16_t)(v11 + 1);
            v10 = (uint16_t)(v10 + v12);
        } while (v9 > v11);
    }
    else
    {
        v10 = 0;
    }
    v13 = (uint16_t)(reply_buf[v4 - 2] + (reply_buf[v4 - 1] << 8));

    if (v13 != v10)
    {
        printf("power reply crc error, crc %04x != crc_reply %04x:\n", v10, v13);
        if (v4)
        {
            v14 = &reply_buf[(uint16_t)(v4 - 1)];
            v15 = reply_buf - 1;
            do
            {
                v16 = *++v15;
                printf("%02x ", v16);
            } while (v14 != v15);
        }
    LABEL_5:
        putchar(10);
        return 0;
    }
    return 1;
}

bool power_send_cmd(uint8_t *cmd, uint8_t len, uint8_t *reply_buf, uint8_t reply_len)
{
    int v4;       // r10
    int v6;       // r6
    uint8_t *v7;  // r5
    int v9;       // r8
    uint8_t *v10; // r4
    int v11;      // t1
    uint8_t *v12; // r4
    bool v13;     // r4
    int v14;      // r2

    v4 = len;
    v6 = 1;
    v7 = &cmd[(uint8_t)(len - 1)];
    v9 = reply_len;
    pthread_mutex_lock(&i2c_mutex);
    do
    {
        if (v4)
        {
            v10 = cmd - 1;
            do
            {
                v11 = *++v10;
                i2c_write(v11 | 0x5201100);
            } while (v10 != v7);
        }
        v12 = reply_buf - 1;
        // usleep((__useconds_t)&gAsic_Core_Nonce_Num[0][73][183]);
        if (v9)
        {
            do
                *++v12 = i2c_read(0x4200000u);
            while (v12 != &reply_buf[(uint8_t)(v9 - 1)]);
        }
        v13 = power_check_reply(cmd, reply_buf, v9);
        if (v13)
            break;
        v14 = v6++;
        printf("power send cmd 0x%02x failed, retry for %d times\n", cmd[3], v14);
    } while (v6 != 4);
    pthread_mutex_unlock(&i2c_mutex);
    return v13;
}

uint8_t APW8_calculate_voltage(unsigned int voltage)
{
    double v1;  // d6
    float v2;   // s16
    uint8_t v3; // r4
    double v4;  // d7
    int v5;     // r3

    if (gHashBoard_BHB91601S)
    {
    LABEL_7:
        v2 = 1215.89444 - (double)voltage * 59.9315068 / 100.0;
        goto LABEL_8;
    }
    if (!gHashBoard_BHB91601P)
    {
        if (!gHashBoard_BHB07601)
        {
            //   printf("\n!!! %s Please check Hashboard type!\n\n", (const char *)_FUNCTION___8046);
            v5 = 255;
            v4 = 255.0;
            v3 = -1;
            goto LABEL_10;
        }
        goto LABEL_7;
    }
    v1 = (double)voltage;
    if (BHB91601_ASIC_NUMBER == 84)
    {
        v2 = 1925.73529 - v1 * 171.875 / 100.0;
    }
    else if (BHB91601_ASIC_NUMBER == 60)
    {
        v2 = 1336.07353 - v1 * 156.145833 / 100.0;
    }
    else
    {
        v2 = 1925.73529 - v1 * 171.875 / 100.0;
        // printf("\n!!! %s Use BHB91601 84P power as default!\n\n", (const char *)_FUNCTION___8046);
    }
LABEL_8:
    v3 = (unsigned int)v2;
    if (v2 >= 0.0)
    {
        v4 = v2;
        v5 = (uint8_t)(unsigned int)v2;
    LABEL_10:
        // printf("\n--- %s: voltage_n = %f, N = %d\n", (const char *)_FUNCTION___8046, v4, v5);
        return v3;
    }
    //   printf("\n!!! %s: voltage_n = %f, we use N = %d as default\n", (const char *)_FUNCTION___8046, v2, 0);
    return 0;
}

void APW8_set_voltage(uint8_t N)
{
    i2c_write(N | 0x5200200);
}

uint8_t APW9_calculate_voltage(unsigned int voltage)
{
    float v1;  // s14
    int v2;    // r4
    double v3; // d7
    int v4;    // r3

    if (!gHashBoard_BHB07601)
    {
        // printf("\n!!! %s Please check Hashboard type!\n\n", (const char *)_FUNCTION___8056);
        v4 = 255;
        v3 = 255.0;
        // LOBYTE(v2) = -1;
        goto LABEL_4;
    }
    v1 = 765.411764 - (double)voltage * 35.833333 / 100.0;
    if (v1 >= 0.0)
    {
        v2 = (uint8_t)(unsigned int)v1;
        v3 = v1;
        v4 = v2;
    LABEL_4:
        // printf("\n--- %s: voltage_n = %f, N = %d\n", (const char *)_FUNCTION___8056, v3, v4);
        return v2;
    }
    //   printf("\n!!! %s: voltage_n = %f, we use N = %d as default\n", (const char *)_FUNCTION___8056, v1, 0);
    return 0;
}

void APW9_set_voltage(uint8_t N)
{
    int16_t v1;        // r6
    uint8_t cmd[8];    // [sp+0h] [bp-38h] BYREF
    uint8_t reply[32]; // [sp+8h] [bp-30h] BYREF

    v1 = N;
    *cmd = -2096715179;
    cmd[5] = 0;
    memset(reply, 0, sizeof(reply));
    cmd[4] = v1;
    *&cmd[6] = v1 + 137;
    power_send_cmd(cmd, 8u, reply, 8u);
}

uint8_t power_calculate_voltage(unsigned int voltage)
{
    if (g_power_type == 1)
        return APW8_calculate_voltage(voltage);
    else
        return APW9_calculate_voltage(voltage);
}

void power_set_voltage(uint8_t N)
{
    if (g_power_type == 1)
        i2c_write(N | 0x5200200);
    else
        APW9_set_voltage(N);
}

int main(int argc, char const *argv[])
{
    pthread_mutex_init(&i2c_mutex, 0);

    return 0;
}
