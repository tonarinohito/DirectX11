#include "Keyboard.h"

void KeyBoard::Run()
{
	in.UpDate();
}
//押している
bool KeyBoard::On(const Key& key)
{
	return in.Push((int)key);
}
//押した
bool KeyBoard::Down(const Key& key)
{
	return in.Press((int)key);
}
//入力がない
bool KeyBoard::Free(const Key& key)
{
	return in.Free((int)key);
}
//離された
bool KeyBoard::Pull(const Key& key)
{
	return in.Pull((int)key);
}