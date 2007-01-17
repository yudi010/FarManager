#ifndef __KEYBAR_HPP__
#define __KEYBAR_HPP__
/*
keybar.hpp

Keybar

*/

#include "scrobj.hpp"

/* $ 07.08.2000 SVS
   ������ �����
*/
enum {
  KBL_MAIN=0,
  KBL_SHIFT,
  KBL_CTRL,
  KBL_ALT,
  KBL_CTRLSHIFT,
  KBL_ALTSHIFT,
  KBL_CTRLALT,

  /* $ 30.04.2001 DJ */
  KBL_GROUP_COUNT
  /* DJ $ */
};
/* SVS $ */

const int KEY_COUNT = 12;

/* $ 30.04.2001 DJ
   �������� typedef; ��������� ������ ����������, ���� ���������� ��
   ������������ ���� � ������
*/

typedef wchar_t KeyBarTitle [10];
typedef KeyBarTitle KeyBarTitleGroup [KEY_COUNT];

class KeyBar: public ScreenObject
{
  private:
    ScreenObject *Owner;

    KeyBarTitleGroup KeyTitles [KBL_GROUP_COUNT];
    int KeyCounts [KBL_GROUP_COUNT];

    int AltState,CtrlState,ShiftState;
    int DisableMask;

  private:
    void DisplayObject();

  public:
    KeyBar();
    void SetOwner(ScreenObject *Owner);
    int ProcessKey(int Key);
    int ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent);

    void SetGroup(int Group,const wchar_t * const *Key,int KeyCount);
    void ClearGroup(int Group);

    void Set(const wchar_t * const *Key,int KeyCount)            { SetGroup (KBL_MAIN, Key, KeyCount); }
    void SetShift(const wchar_t * const *Key,int KeyCount)       { SetGroup (KBL_SHIFT, Key, KeyCount); }
    void SetAlt(const wchar_t * const *Key,int KeyCount)         { SetGroup (KBL_ALT, Key, KeyCount); }
    void SetCtrl(const wchar_t * const *Key,int KeyCount)        { SetGroup (KBL_CTRL, Key, KeyCount); }
    /* $ 02.08.2000 SVS
       �������������� ����������
    */
    void SetCtrlShift(const wchar_t * const *Key,int KeyCount)   { SetGroup (KBL_CTRLSHIFT, Key, KeyCount); }
    void SetAltShift(const wchar_t * const *Key,int KeyCount)    { SetGroup (KBL_ALTSHIFT, Key, KeyCount); }
    void SetCtrlAlt(const wchar_t **Key,int KeyCount)     { SetGroup (KBL_CTRLALT, Key, KeyCount); }
    /* SVS $*/

    void SetDisableMask(int Mask);
    void Change(const wchar_t *NewStr,int Pos)            { Change (KBL_MAIN, NewStr, Pos); }

    /* $ 07.08.2000 SVS
       ��������� ������ Label
    */
    void Change(int Group,const wchar_t *NewStr,int Pos);
    /* SVS $ */

    /* $ 30.04.2001 DJ
       ��������� ��������� ������ ������ ����� LNG ��� ��������� ������
    */
    void SetAllGroup (int Group, int StartIndex, int Count);
    /* DJ $ */

    void RedrawIfChanged();
    void ResizeConsole();
};

/* DJ $ */

#endif  // __KEYBAR_HPP__
