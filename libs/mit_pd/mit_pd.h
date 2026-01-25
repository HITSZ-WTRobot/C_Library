/**
 * @file    mit_pd.h
 * @author  syhanjin
 * @date    2026-01-02
 * @brief   Brief description of the file
 *
 * Detailed description (optional).
 *
 */
#ifndef MIT_PD_H
#define MIT_PD_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    float Kp;
    float Kd;
    float abs_output_max;

    /* Runtime */
    float p_ref; ///< 位置参考
    float p_fdb; ///< 位置反馈
    float v_ref; ///< 速度参考
    float v_fdb; ///< 速度反馈

    /**
     * 输出量
     *
     * output = kp * (p_ref - p_fdb) + kd * (v_ref - v_fdb);
     */
    float output;
} MIT_PD_t;

typedef struct
{
    float Kp;
    float Kd;
    float abs_output_max;
} MIT_PD_Config_t;

void MIT_PD_Init(MIT_PD_t* pd, const MIT_PD_Config_t* config);
void MIT_PD_Calculate(MIT_PD_t* pd);

static void MIT_PD_Reset(MIT_PD_t* pd)
{
    pd->p_ref  = 0.0f;
    pd->p_fdb  = 0.0f;
    pd->v_ref  = 0.0f;
    pd->v_fdb  = 0.0f;
    pd->output = 0.0f;
}

#ifdef __cplusplus
}
#endif

#endif // MIT_PD_H
