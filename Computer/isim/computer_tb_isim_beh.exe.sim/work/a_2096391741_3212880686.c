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
static const char *ng0 = "D:/Work/Programming/Projects/Computer Architecture Project/CPU 8/CPU_FINAL_2/CPU_FINAL/ControlUnit.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1258338084_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2096391741_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    char *t10;

LAB0:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 4032U);
    t4 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t4 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 4032U);
    t9 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    t3 = t9;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:    t1 = (t0 + 992U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 9480);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 9576);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(109, ng0);
    t5 = (t0 + 9576);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t5);
    goto LAB3;

LAB7:    t3 = (unsigned char)1;
    goto LAB9;

LAB10:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4392U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t2 = (t0 + 9576);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((unsigned char *)t10) = t4;
    xsi_driver_first_trans_fast(t2);
    goto LAB3;

}

static void work_a_2096391741_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    unsigned char t9;
    char *t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5, &&LAB6, &&LAB7, &&LAB8, &&LAB14, &&LAB9, &&LAB10, &&LAB11, &&LAB12, &&LAB13, &&LAB15, &&LAB16, &&LAB17, &&LAB18, &&LAB19};

LAB0:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 9640);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(119, ng0);
    t1 = (t0 + 9704);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 9832);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 9896);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(123, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(124, ng0);
    t1 = (t0 + 10024);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(125, ng0);
    t1 = (t0 + 10088);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(126, ng0);
    t1 = (t0 + 10152);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 10216);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(129, ng0);
    t1 = (t0 + 4232U);
    t2 = *((char **)t1);
    t6 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t6);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 9496);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(131, ng0);
    t3 = (t0 + 9640);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 9704);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(134, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 19194);
    t4 = ((IEEE_P_2592010699) + 4024);
    t9 = xsi_vhdl_greaterEqual(t4, t2, 8U, t1, 8U);
    if (t9 == 1)
        goto LAB24;

LAB25:    t6 = (unsigned char)0;

LAB26:    if (t6 != 0)
        goto LAB21;

LAB23:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7328U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB29;

LAB30:    t6 = 0;

LAB31:    if (t6 != 0)
        goto LAB27;

LAB28:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7568U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB37;

LAB38:    t6 = 0;

LAB39:    if (t6 != 0)
        goto LAB35;

LAB36:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7448U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB45;

LAB46:    t6 = 0;

LAB47:    if (t6 != 0)
        goto LAB43;

LAB44:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7688U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB53;

LAB54:    t6 = 0;

LAB55:    if (t6 != 0)
        goto LAB51;

LAB52:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7808U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB61;

LAB62:    t6 = 0;

LAB63:    if (t6 != 0)
        goto LAB59;

LAB60:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7928U);
    t3 = *((char **)t1);
    t6 = 1;
    if (8U == 8U)
        goto LAB69;

LAB70:    t6 = 0;

LAB71:    if (t6 != 0)
        goto LAB67;

LAB68:
LAB22:    goto LAB2;

LAB4:    xsi_set_current_line(163, ng0);
    t1 = (t0 + 19220);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(164, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(165, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 9832);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(169, ng0);
    t1 = (t0 + 19222);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(170, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(172, ng0);
    t1 = (t0 + 19224);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(173, ng0);
    t1 = (t0 + 10408);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(175, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 10472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    memcpy(t7, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(177, ng0);
    t1 = (t0 + 19226);
    t3 = (t0 + 10536);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(178, ng0);
    t1 = (t0 + 9896);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(179, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(181, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB7:    xsi_set_current_line(185, ng0);
    t1 = (t0 + 19228);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(186, ng0);
    t1 = (t0 + 19230);
    t3 = (t0 + 10536);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(187, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(188, ng0);
    t1 = (t0 + 9896);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(190, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB8:    xsi_set_current_line(194, ng0);
    t1 = (t0 + 19232);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(195, ng0);
    t1 = (t0 + 19234);
    t3 = (t0 + 10536);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(196, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(197, ng0);
    t1 = (t0 + 9896);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(199, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB9:    xsi_set_current_line(203, ng0);
    t1 = (t0 + 19236);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(204, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(208, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)8;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB10:    xsi_set_current_line(212, ng0);
    t1 = (t0 + 9832);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(213, ng0);
    t1 = (t0 + 19238);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(216, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)9;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB11:    xsi_set_current_line(220, ng0);
    t1 = (t0 + 19240);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(222, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)10;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB12:    xsi_set_current_line(225, ng0);
    t1 = (t0 + 10216);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(226, ng0);
    t1 = (t0 + 10152);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(228, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)11;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB13:    xsi_set_current_line(232, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(234, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB14:    xsi_set_current_line(237, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(238, ng0);
    t1 = (t0 + 10088);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(239, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB15:    xsi_set_current_line(243, ng0);
    t1 = (t0 + 19242);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(244, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(245, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)13;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB16:    xsi_set_current_line(248, ng0);
    t1 = (t0 + 19244);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(249, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(250, ng0);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t6 = *((unsigned char *)t2);
    t9 = (t6 == (unsigned char)3);
    if (t9 != 0)
        goto LAB75;

LAB77:    xsi_set_current_line(253, ng0);
    t1 = (t0 + 19248);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);

LAB76:    xsi_set_current_line(256, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)14;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB17:    xsi_set_current_line(260, ng0);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t6 = *((unsigned char *)t2);
    t9 = (t6 == (unsigned char)3);
    if (t9 != 0)
        goto LAB78;

LAB80:    xsi_set_current_line(263, ng0);
    t1 = (t0 + 19252);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);

LAB79:    xsi_set_current_line(267, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)6;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB18:    xsi_set_current_line(269, ng0);
    t1 = (t0 + 9960);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(270, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)16;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB19:    xsi_set_current_line(272, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)15;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB20:    xsi_set_current_line(274, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB21:    xsi_set_current_line(135, ng0);
    t12 = (t0 + 19210);
    t14 = (t0 + 10280);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t12, 2U);
    xsi_driver_first_trans_fast_port(t14);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(137, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB24:    t5 = (t0 + 1672U);
    t7 = *((char **)t5);
    t5 = (t0 + 19202);
    t10 = ((IEEE_P_2592010699) + 4024);
    t11 = xsi_vhdl_lessthanEqual(t10, t7, 8U, t5, 8U);
    t6 = t11;
    goto LAB26;

LAB27:    xsi_set_current_line(139, ng0);
    t5 = (t0 + 10024);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(140, ng0);
    t1 = (t0 + 19212);
    t3 = (t0 + 10280);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t1, 2U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(141, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(142, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)12;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB29:    t19 = 0;

LAB32:    if (t19 < 8U)
        goto LAB33;
    else
        goto LAB31;

LAB33:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB30;

LAB34:    t19 = (t19 + 1);
    goto LAB32;

LAB35:    xsi_set_current_line(144, ng0);
    t5 = (t0 + 10024);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(145, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(146, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB37:    t19 = 0;

LAB40:    if (t19 < 8U)
        goto LAB41;
    else
        goto LAB39;

LAB41:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB38;

LAB42:    t19 = (t19 + 1);
    goto LAB40;

LAB43:    xsi_set_current_line(148, ng0);
    t5 = (t0 + 19214);
    t8 = (t0 + 10280);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t5, 2U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(149, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(150, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB45:    t19 = 0;

LAB48:    if (t19 < 8U)
        goto LAB49;
    else
        goto LAB47;

LAB49:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB46;

LAB50:    t19 = (t19 + 1);
    goto LAB48;

LAB51:    xsi_set_current_line(152, ng0);
    t5 = (t0 + 19216);
    t8 = (t0 + 10280);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t5, 2U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(153, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)6;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB53:    t19 = 0;

LAB56:    if (t19 < 8U)
        goto LAB57;
    else
        goto LAB55;

LAB57:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB54;

LAB58:    t19 = (t19 + 1);
    goto LAB56;

LAB59:    xsi_set_current_line(155, ng0);
    t5 = (t0 + 19218);
    t8 = (t0 + 10280);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t5, 2U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(156, ng0);
    t1 = (t0 + 9768);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(157, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)7;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB61:    t19 = 0;

LAB64:    if (t19 < 8U)
        goto LAB65;
    else
        goto LAB63;

LAB65:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB62;

LAB66:    t19 = (t19 + 1);
    goto LAB64;

LAB67:    xsi_set_current_line(159, ng0);
    t5 = (t0 + 9960);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(160, ng0);
    t1 = (t0 + 10344);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)15;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB69:    t19 = 0;

LAB72:    if (t19 < 8U)
        goto LAB73;
    else
        goto LAB71;

LAB73:    t1 = (t2 + t19);
    t4 = (t3 + t19);
    if (*((unsigned char *)t1) != *((unsigned char *)t4))
        goto LAB70;

LAB74:    t19 = (t19 + 1);
    goto LAB72;

LAB75:    xsi_set_current_line(251, ng0);
    t1 = (t0 + 19246);
    t4 = (t0 + 10280);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB76;

LAB78:    xsi_set_current_line(261, ng0);
    t1 = (t0 + 19250);
    t4 = (t0 + 10280);
    t5 = (t4 + 56U);
    t7 = *((char **)t5);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB79;

}


extern void work_a_2096391741_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2096391741_3212880686_p_0,(void *)work_a_2096391741_3212880686_p_1};
	xsi_register_didat("work_a_2096391741_3212880686", "isim/computer_tb_isim_beh.exe.sim/work/a_2096391741_3212880686.didat");
	xsi_register_executes(pe);
}
