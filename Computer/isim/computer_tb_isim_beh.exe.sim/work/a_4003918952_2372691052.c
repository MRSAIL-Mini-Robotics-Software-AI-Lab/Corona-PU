/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Work/Programming/Projects/Computer Architecture Project/CPU 8/CPU_FINAL_2/CPU_FINAL/VGA_Control.vhd";
extern char *IEEE_P_2592010699;
extern char *STD_TEXTIO;
extern char *IEEE_P_3564397177;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
void ieee_p_3564397177_sub_1281154728_91900896(char *, char *, char *, char *, char *, unsigned char , int );
void ieee_p_3564397177_sub_1496949865_91900896(char *, char *, char *, unsigned char , unsigned char , int );


static void work_a_4003918952_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(43, ng0);

LAB3:    t1 = (t0 + 8112);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4003918952_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(44, ng0);

LAB3:    t1 = (t0 + 8176);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4003918952_2372691052_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2912U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 7920);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 3112U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)2);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 8240);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 2952U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 8240);
    t11 = (t4 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t4);
    goto LAB9;

}

static void work_a_4003918952_2372691052_p_3(char *t0)
{
    char t37[16];
    char t38[8];
    char t39[8];
    char t40[8];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    int t10;
    unsigned char t11;
    int t12;
    int t13;
    char *t14;
    int t15;
    int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned char t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned char t28;
    unsigned char t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    int64 t36;

LAB0:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 7936);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 5328U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(64, ng0);
    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(65, ng0);
    t3 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, (unsigned char)2);
    t1 = (t0 + 8304);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(66, ng0);
    t3 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, (unsigned char)3);
    t1 = (t0 + 8368);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 8432);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 8496);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 8560);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 5328U);
    t6 = *((char **)t2);
    t10 = *((int *)t6);
    t11 = (t10 < 1055);
    if (t11 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(77, ng0);
    t1 = (t0 + 5328U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(78, ng0);
    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t3 = (t10 < 627);
    if (t3 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;

LAB14:
LAB11:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 5328U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t12 = (800 + 40);
    t4 = (t10 < t12);
    if (t4 == 1)
        goto LAB19;

LAB20:    t1 = (t0 + 5328U);
    t5 = *((char **)t1);
    t13 = *((int *)t5);
    t15 = (800 + 40);
    t16 = (t15 + 128);
    t8 = (t13 >= t16);
    t3 = t8;

LAB21:    if (t3 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 8304);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB17:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t12 = (600 + 1);
    t4 = (t10 < t12);
    if (t4 == 1)
        goto LAB25;

LAB26:    t1 = (t0 + 5448U);
    t5 = *((char **)t1);
    t13 = *((int *)t5);
    t15 = (600 + 1);
    t16 = (t15 + 4);
    t8 = (t13 >= t16);
    t3 = t8;

LAB27:    if (t3 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 8368);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB23:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 5328U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t3 = (t10 < 800);
    if (t3 != 0)
        goto LAB28;

LAB30:
LAB29:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 5448U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t3 = (t10 < 600);
    if (t3 != 0)
        goto LAB31;

LAB33:
LAB32:    xsi_set_current_line(108, ng0);
    t1 = (t0 + 5328U);
    t2 = *((char **)t1);
    t10 = *((int *)t2);
    t4 = (t10 < 800);
    if (t4 == 1)
        goto LAB37;

LAB38:    t3 = (unsigned char)0;

LAB39:    if (t3 != 0)
        goto LAB34;

LAB36:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 8432);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB35:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 8624);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t14 = *((char **)t7);
    memcpy(t14, t2, 3U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 8688);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t14 = *((char **)t7);
    memcpy(t14, t2, 3U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(118, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 8752);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t14 = *((char **)t7);
    memcpy(t14, t2, 3U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(119, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t10 = (2 - 2);
    t18 = (t10 * -1);
    t19 = (1U * t18);
    t20 = (0 + t19);
    t1 = (t2 + t20);
    t8 = *((unsigned char *)t1);
    t9 = (t8 == (unsigned char)0);
    if (t9 == 1)
        goto LAB46;

LAB47:    t5 = (t0 + 1512U);
    t6 = *((char **)t5);
    t12 = (1 - 2);
    t21 = (t12 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t5 = (t6 + t23);
    t11 = *((unsigned char *)t5);
    t24 = (t11 == (unsigned char)0);
    t4 = t24;

LAB48:    if (t4 == 1)
        goto LAB43;

LAB44:    t7 = (t0 + 1512U);
    t14 = *((char **)t7);
    t13 = (0 - 2);
    t25 = (t13 * -1);
    t26 = (1U * t25);
    t27 = (0 + t26);
    t7 = (t14 + t27);
    t28 = *((unsigned char *)t7);
    t29 = (t28 == (unsigned char)0);
    t3 = t29;

LAB45:    if (t3 != 0)
        goto LAB40;

LAB42:
LAB41:    xsi_set_current_line(122, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t10 = (2 - 2);
    t18 = (t10 * -1);
    t19 = (1U * t18);
    t20 = (0 + t19);
    t1 = (t2 + t20);
    t8 = *((unsigned char *)t1);
    t9 = (t8 == (unsigned char)0);
    if (t9 == 1)
        goto LAB55;

LAB56:    t5 = (t0 + 1672U);
    t6 = *((char **)t5);
    t12 = (1 - 2);
    t21 = (t12 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t5 = (t6 + t23);
    t11 = *((unsigned char *)t5);
    t24 = (t11 == (unsigned char)0);
    t4 = t24;

LAB57:    if (t4 == 1)
        goto LAB52;

LAB53:    t7 = (t0 + 1672U);
    t14 = *((char **)t7);
    t13 = (0 - 2);
    t25 = (t13 * -1);
    t26 = (1U * t25);
    t27 = (0 + t26);
    t7 = (t14 + t27);
    t28 = *((unsigned char *)t7);
    t29 = (t28 == (unsigned char)0);
    t3 = t29;

LAB54:    if (t3 != 0)
        goto LAB49;

LAB51:
LAB50:    xsi_set_current_line(125, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t10 = (2 - 2);
    t18 = (t10 * -1);
    t19 = (1U * t18);
    t20 = (0 + t19);
    t1 = (t2 + t20);
    t8 = *((unsigned char *)t1);
    t9 = (t8 == (unsigned char)0);
    if (t9 == 1)
        goto LAB64;

LAB65:    t5 = (t0 + 1832U);
    t6 = *((char **)t5);
    t12 = (1 - 2);
    t21 = (t12 * -1);
    t22 = (1U * t21);
    t23 = (0 + t22);
    t5 = (t6 + t23);
    t11 = *((unsigned char *)t5);
    t24 = (t11 == (unsigned char)0);
    t4 = t24;

LAB66:    if (t4 == 1)
        goto LAB61;

LAB62:    t7 = (t0 + 1832U);
    t14 = *((char **)t7);
    t13 = (0 - 2);
    t25 = (t13 * -1);
    t26 = (1U * t25);
    t27 = (0 + t26);
    t7 = (t14 + t27);
    t28 = *((unsigned char *)t7);
    t29 = (t28 == (unsigned char)0);
    t3 = t29;

LAB63:    if (t3 != 0)
        goto LAB58;

LAB60:
LAB59:    xsi_set_current_line(130, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t36 = xsi_get_sim_current_time();
    std_textio_write8(STD_TEXTIO, t1, t2, t36, (unsigned char)0, 0, 1000LL);
    xsi_set_current_line(131, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15157);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(134, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15158);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(135, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 2792U);
    t6 = *((char **)t5);
    t3 = *((unsigned char *)t6);
    ieee_p_3564397177_sub_1496949865_91900896(IEEE_P_3564397177, t1, t2, t3, (unsigned char)0, 0);
    xsi_set_current_line(138, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15159);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(139, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 2952U);
    t6 = *((char **)t5);
    t3 = *((unsigned char *)t6);
    ieee_p_3564397177_sub_1496949865_91900896(IEEE_P_3564397177, t1, t2, t3, (unsigned char)0, 0);
    xsi_set_current_line(142, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15160);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(143, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 3272U);
    t6 = *((char **)t5);
    memcpy(t38, t6, 3U);
    t5 = (t0 + 14940U);
    ieee_p_3564397177_sub_1281154728_91900896(IEEE_P_3564397177, t1, t2, t38, t5, (unsigned char)0, 0);
    xsi_set_current_line(146, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15161);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(147, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 3432U);
    t6 = *((char **)t5);
    memcpy(t39, t6, 3U);
    t5 = (t0 + 14940U);
    ieee_p_3564397177_sub_1281154728_91900896(IEEE_P_3564397177, t1, t2, t39, t5, (unsigned char)0, 0);
    xsi_set_current_line(150, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 15162);
    t7 = (t37 + 0U);
    t14 = (t7 + 0U);
    *((int *)t14) = 1;
    t14 = (t7 + 4U);
    *((int *)t14) = 1;
    t14 = (t7 + 8U);
    *((int *)t14) = 1;
    t10 = (1 - 1);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t14 = (t7 + 12U);
    *((unsigned int *)t14) = t18;
    std_textio_write7(STD_TEXTIO, t1, t2, t5, t37, (unsigned char)0, 0);
    xsi_set_current_line(151, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5952U);
    t5 = (t0 + 3592U);
    t6 = *((char **)t5);
    memcpy(t40, t6, 3U);
    t5 = (t0 + 14940U);
    ieee_p_3564397177_sub_1281154728_91900896(IEEE_P_3564397177, t1, t2, t40, t5, (unsigned char)0, 0);
    xsi_set_current_line(153, ng0);
    t1 = (t0 + 7160);
    t2 = (t0 + 5776U);
    t5 = (t0 + 5952U);
    std_textio_writeline(STD_TEXTIO, t1, t2, t5);
    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    t3 = t9;
    goto LAB9;

LAB10:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 5328U);
    t7 = *((char **)t2);
    t12 = *((int *)t7);
    t13 = (t12 + 1);
    t2 = (t0 + 5328U);
    t14 = *((char **)t2);
    t2 = (t14 + 0);
    *((int *)t2) = t13;
    goto LAB11;

LAB13:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 5448U);
    t5 = *((char **)t1);
    t12 = *((int *)t5);
    t13 = (t12 + 1);
    t1 = (t0 + 5448U);
    t6 = *((char **)t1);
    t1 = (t6 + 0);
    *((int *)t1) = t13;
    goto LAB14;

LAB16:    xsi_set_current_line(87, ng0);
    t9 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, (unsigned char)2);
    t1 = (t0 + 8304);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t14 = (t7 + 56U);
    t17 = *((char **)t14);
    *((unsigned char *)t17) = t9;
    xsi_driver_first_trans_fast(t1);
    goto LAB17;

LAB19:    t3 = (unsigned char)1;
    goto LAB21;

LAB22:    xsi_set_current_line(94, ng0);
    t9 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, (unsigned char)3);
    t1 = (t0 + 8368);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t14 = (t7 + 56U);
    t17 = *((char **)t14);
    *((unsigned char *)t17) = t9;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

LAB25:    t3 = (unsigned char)1;
    goto LAB27;

LAB28:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 5328U);
    t5 = *((char **)t1);
    t12 = *((int *)t5);
    t1 = (t0 + 8496);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t14 = (t7 + 56U);
    t17 = *((char **)t14);
    *((int *)t17) = t12;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB29;

LAB31:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 5448U);
    t5 = *((char **)t1);
    t12 = *((int *)t5);
    t1 = (t0 + 8560);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t14 = (t7 + 56U);
    t17 = *((char **)t14);
    *((int *)t17) = t12;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB32;

LAB34:    xsi_set_current_line(109, ng0);
    t1 = (t0 + 8432);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t14 = (t7 + 56U);
    t17 = *((char **)t14);
    *((unsigned char *)t17) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB35;

LAB37:    t1 = (t0 + 5448U);
    t5 = *((char **)t1);
    t12 = *((int *)t5);
    t8 = (t12 < 600);
    t3 = t8;
    goto LAB39;

LAB40:    xsi_set_current_line(120, ng0);
    t17 = (t0 + 15148);
    t31 = (t0 + 8624);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t17, 3U);
    xsi_driver_first_trans_fast(t31);
    goto LAB41;

LAB43:    t3 = (unsigned char)1;
    goto LAB45;

LAB46:    t4 = (unsigned char)1;
    goto LAB48;

LAB49:    xsi_set_current_line(123, ng0);
    t17 = (t0 + 15151);
    t31 = (t0 + 8688);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t17, 3U);
    xsi_driver_first_trans_fast(t31);
    goto LAB50;

LAB52:    t3 = (unsigned char)1;
    goto LAB54;

LAB55:    t4 = (unsigned char)1;
    goto LAB57;

LAB58:    xsi_set_current_line(126, ng0);
    t17 = (t0 + 15154);
    t31 = (t0 + 8752);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t17, 3U);
    xsi_driver_first_trans_fast(t31);
    goto LAB59;

LAB61:    t3 = (unsigned char)1;
    goto LAB63;

LAB64:    t4 = (unsigned char)1;
    goto LAB66;

}

static void work_a_4003918952_2372691052_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(157, ng0);

LAB3:    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 8816);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 8032);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_4003918952_2372691052_init()
{
	static char *pe[] = {(void *)work_a_4003918952_2372691052_p_0,(void *)work_a_4003918952_2372691052_p_1,(void *)work_a_4003918952_2372691052_p_2,(void *)work_a_4003918952_2372691052_p_3,(void *)work_a_4003918952_2372691052_p_4};
	xsi_register_didat("work_a_4003918952_2372691052", "isim/computer_tb_isim_beh.exe.sim/work/a_4003918952_2372691052.didat");
	xsi_register_executes(pe);
}
