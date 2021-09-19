#include "Character.h"


/*
	����Ű�� ������ ��������Ʈ�ڽ��� ����

	�������� 100���� �ؽ�Ʈ�ƿ����� ǥ��
	��Ʈ�ڽ��� 5�����ӵ��� ����
	5�����ӵ��� Ű�� �Է��ص� �������� ����

	������ 5�����ӵ��� �����ȿ� ���� ������ 10�� ����

	��Ʈ : 

	��Ʈ�ڽ��� �Ѱ� ���� �Լ��� ��������

	turnOnHitBox ();
	turnOffHitBox();

	����Ű�� �ΰ��Ұ�.
	�Ѱ��� �а� ª����
	�Ѱ��� ª�� ���.

	�ΰ��� ��Ʈ�ڽ� �¿����� ���ε��� �����

	turnOn����HitBox ();
	turnOff����HitBox();
	turnOn��HitBox ();
	turnOff��HitBox();
	allhitboxoff();

	ĳ���������Ͱ� ���� �迭�� ������ (���͸� �̿��غ���) 

	�ݺ��� ����� ĳ���� �ּҰ� �ִ��� ����Ȯ�� �� ������ ����
	���԰� ���ÿ� ������ 

	��Ʈ�ڽ� ����ȭ

	ĳ������ ������ȯ����

*/

void Character::Init()
{
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	bodySize = 25;
	mHP = 100;
	
	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;

	moveSpeed = 10.0f;
}

void Character::Update()
{
	mFrame++;
	cout << mFrame << endl;

	if (mFrame >= 5)
	{
		AllOffHitBox();
	}

	shape.left = (int)pos.x - bodySize;
	shape.top = (int)pos.y - bodySize;
	shape.right = (int)pos.x + bodySize;
	shape.bottom = (int)pos.y + bodySize;
}

void Character::Render(HDC hdc)
{
	Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);

	if (mTarget && IsCollided(mSmallHitBox, mTarget->shape))
	{	
		TextOut(hdc,(int) mTarget->pos.x, (int)mTarget->pos.y + 100 , "���� ���� ��Ʈ!!!!!!!!!!!!", strlen("���� ���� ��Ʈ!!!!!!!!!!!!"));
	}

	if (mTarget && IsCollided(mBigHitBox, mTarget->shape))
	{

		TextOut(hdc, (int)mTarget->pos.x, (int)mTarget->pos.y + 100 , "ū ���� ��Ʈ!!!!!!!!!!!!", strlen("ū ���� ��Ʈ!!!!!!!!!!!!"));
	}
}

void Character::Release()
{
}

void Character::Move(int dir)
{
	if (dir > 0)
	{
		if (IsCollided(this->shape,mTarget->shape))
		{
			if (mTarget->pos.x < this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x + bodySize > mTarget->pos.x - bodySize && !(mTarget->pos.x < this->pos.x))
			{
				this->pos.x -= (this->pos.x + bodySize) - (mTarget->pos.x - bodySize);
			}
		}
	}
	else
	{
		if (IsCollided(this->shape, mTarget->shape))
		{
			if (mTarget->pos.x > this->pos.x)
			{
				pos.x += moveSpeed * dir;
			}
		}
		else
		{
			pos.x += moveSpeed * dir;

			if (this->pos.x - bodySize < mTarget->pos.x + bodySize && !(mTarget->pos.x > this->pos.x))
			{
				this->pos.x -= (this->pos.x - bodySize) - (mTarget->pos.x + bodySize);
			}
		}
	}
}

void Character::OffSmallHitBox()
{
	mSmallHitBox = RECT();
}

void Character::OnBigHitBox()
{
	if (mFrame >= 5)
	{
		mFrame = 0;

		mBigHitBox.left = (int)pos.x;
		mBigHitBox.top = (int)pos.y - 50;
		mBigHitBox.right = (int)pos.x + 70;
		mBigHitBox.bottom = (int)pos.y + 50;
	}
}

void Character::OffBigHitBox()
{
	mBigHitBox = RECT();
}

void Character::AllOffHitBox()
{
	mSmallHitBox = RECT();
	mBigHitBox = RECT();
}

void Character::OnSmallHitBox()
{
	if (mFrame >= 5)
	{
		mFrame = 0;

		mSmallHitBox.left = (int)pos.x;
		mSmallHitBox.top = (int)pos.y - 20;
		mSmallHitBox.right = (int)pos.x + 100;
		mSmallHitBox.bottom = (int)pos.y;
	}
}