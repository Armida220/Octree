#pragma once
//������Ķ���

class Object
{
public:
	Object(float _x, float _y, float _z, float _xSize, float _ySize, float _zSize);
	~Object();
public:
	//��������ԣ���������ͳ���ߣ������Ͻ�Ϊê��
	float x;
	float y;
	float z;
	float xSize;
	float ySize;
	float zSize;
};