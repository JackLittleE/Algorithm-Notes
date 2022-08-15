#pragma once
#include <vector>
#include <complex>


// �źŴ������㷨
namespace Signal
{

	/*-------------------- transform.cpp --------------------*/


	/*
	* @fn - dft
	* �����������е���ɢ����Ҷ�任(Discrete Fourier Transform, DFT)
	* 
	* @para x - ��������
	* 
	* @retn - �������� x �� DFT �任���
	*/
	std::vector<std::complex<double>> dft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - idft
	* �����������е���ɢ����Ҷ��任(Inverse Discrete Fourier Transform, IDFT)
	* 
	* @para x - ��������
	* 
	* @retn - �������� x �� IDFT �任���
	*/
	std::vector<std::complex<double>> idft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - fft
	* �����������еĿ��ٸ���Ҷ�任(Fast Fourier Transform, FFT)
	*
	* @para x - ��������
	*
	* @retn - �������� x �� FFT �任���
	*
	* @note : �������� x �ĳ��ȱ���Ϊ 2 ����������
	*/
	std::vector<std::complex<double>> fft(const std::vector<double>& x);


	/*
	* @fn - fft
	* �����������еĿ��ٸ���Ҷ�任(Fast Fourier Transform, FFT)
	*
	* @para x - ��������
	*
	* @retn - �������� x �� FFT �任���
	* 
	* @note : �������� x �ĳ��ȱ���Ϊ 2 ����������
	*/
	std::vector<std::complex<double>> fft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - ifft
	* �����������еĿ��ٸ���Ҷ��任(Inverse Fast Fourier Transform, IFFT)
	*
	* @para x - ��������
	*
	* @retn - �������� x �� IFFT �任���
	*
	* @note : �������� x �ĳ��ȱ���Ϊ 2 ����������
	*/
	std::vector<std::complex<double>> ifft(const std::vector<std::complex<double>>& x);


	/*
	* @fn - Hilbert
	* �����������е�ϣ������(hilbert)�任
	*
	* @para x - ��������
	*
	* @retn - �������� x ��ϣ�����ر任���(ʵ�źŶ�Ӧ�����ź�)
	*
	* @note : �������� x �ĳ��ȱ���Ϊ 2 ����������
	*/
	std::vector<double> hilbert(const std::vector<double>& x);


	/*
	* @fn - Hilbert
	* ʹ�� fft �����������е�ϣ������(hilbert)�任
	*
	* @para fft - ��������(x)�� fft �任
	*
	* @retn - �������� x ��ϣ�����ر任���(ʵ�źŶ�Ӧ�����ź�)
	*
	* @note : �������� x �ĳ��ȱ���Ϊ 2 ����������
	*/
	std::vector<double> hilbert_fft(const std::vector<std::complex<double>>& fft);

}