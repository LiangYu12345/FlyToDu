#pragma once

#define BigLittleSwap16(A) 		((((unsigned short)(A) & 0xff00) >> 8) | \
	(((unsigned short)(A)& 0x00ff) << 8))

#define BigLittleSwap32(A) 		((((unsigned int)(A) & 0xff000000) >> 24) | \
	(((unsigned int)(A)& 0x00ff0000) >> 8) | \
	(((unsigned int)(A)& 0x0000ff00) << 8) | \
	(((unsigned int)(A)& 0x000000ff) << 24))

#define BigLittleSwap64(A) 		((((unsigned long long)(A) & 0xff00000000000000) >> 56) | \
	(((unsigned long long)(A)& 0x00ff000000000000) >> 40) | \
	(((unsigned long long)(A)& 0x0000ff0000000000) >> 24) | \
	(((unsigned long long)(A)& 0x000000ff00000000) >> 8) | \
	(((unsigned long long)(A)& 0x00000000ff000000) << 8) | \
	(((unsigned long long)(A)& 0x0000000000ff0000) << 24) | \
	(((unsigned long long)(A)& 0x000000000000ff00) << 40) | \
	(((unsigned long long)(A)& 0x00000000000000ff) << 56))


typedef union _IntWithFloat32
{
    unsigned int m_i32;
    float m_f32;
}IntWithFloat32;

typedef union _IntWithFloat64
{
    long long m_i64;
    double m_f64;
}IntWithFloat64;

float HmsSwapFloat32(float value)
{
    IntWithFloat32 tmp;
    tmp.m_f32 = value;
    tmp.m_i32 = BigLittleSwap32(tmp.m_i32);
    return tmp.m_f32;
}

double HmsSwapFloat64(double value)
{
    IntWithFloat64 tmp;
    tmp.m_f64 = value;
    tmp.m_i64 = BigLittleSwap64(tmp.m_i64);
    return tmp.m_f64;
}
