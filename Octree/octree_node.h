/*
//�˲����ڵ��࣬��ͷ�ڵ����˲���
//����opengl��������ϵ������ԭ����Ǹ���Ϊê�㣬�������
//���˲����Ĳ����ǣ�1��һ�λ������нڵ㣬��������2����������ռ���ȫ����ĳ������޳�,��������ռ���ĳ�����ཻ������ȫ����ʱ�Ų�ѯ��3�����������ȫ������������Ҷ�ӽڵ��ڣ��Ǹ��ڵ㲻�洢����Ĭ��Ϊ���岻���ܿ���Ҷ�ӽڵ㣬����һ��Ҷ�ӽڵ�Ŀռ䷶Χ�ڲ���δ���ǽ�������
*/
#pragma once
#include <list>

//�˲����ڵ�����
enum OctreeType
{
	ROOT,                   //��
	BOTTOM_LEFT_FRONT,		// 1 
	BOTTOM_RIGHT_FRONT,		// 2 
	BOTTOM_LEFT_BACK,		// 3 
	BOTTOM_RIGHT_BACK,      // 4 
	TOP_LEFT_FRONT,         // 5 
	TOP_RIGHT_FRONT,        // 6 
	TOP_LEFT_BACK,          // 7 
	TOP_RIGHT_BACK          // 8   
};

template <class T>
class OctreeNode
{
public:
	OctreeNode(float _x, float _y, float _z, float _xSize, float _ySize, float _zSize, OctreeType _octreeNodeType, int _level, int _maxLevel);
	~OctreeNode();
public:
	void BuildTree(int level); //�����˲��������ֵ������ӽڵ�
	void InsertObject(T *object); //�������
	std::list<T *> GetObjectsAt(float px, float py, float pz, float x_size, float y_size, float z_size); //��ѯ����,���һƬ������Ķ�������,���ǰ������ཻ,����
	void RemoveObjectsAt(float px, float py, float pz, float x_size, float y_size, float z_size); //ɾ������ɾ��һƬ������Ķ��󣬴˴�ֻ������ȫ������
private:
	bool IsContain(float px, float py, float pz, float x_size, float y_size, float z_size, T *object) const; //�ж�ĳ�������Ƿ����ĳ����
	bool IsContain(float px, float py, float pz, float x_size, float y_size, float z_size, OctreeNode<T> *octreeNode) const; //���أ��ж�ĳ�������Ƿ����ĳ���ڵ�
	bool IsInterSect(float px, float py, float pz, float x_size, float y_size, float z_size, OctreeNode<T> *octreeNode) const; //�ж�ĳ�������Ƿ���ڵ��ཻ������ཻ�����ѯʱҪ�ݹ鵽���ӽڵ�
public:
	std::list<T *> objectList; //�ڵ�洢�Ķ����б�
private:
	//�ڵ�����
	OctreeType octreeNodeType;
	float x;
	float y;
	float z;
	float xSize;
	float ySize;
	float zSize;
	int level;
	int maxLevel;
	//�ӽڵ�,����opengl����ϵ��������������
	OctreeNode *bottom_left_front_node;
	OctreeNode *bottom_right_front_node;
	OctreeNode *bottom_left_back_node;
	OctreeNode *bottom_right_back_node;
	OctreeNode *top_left_front_node;
	OctreeNode *top_right_front_node;
	OctreeNode *top_left_back_node;
	OctreeNode *top_right_back_node;
};
