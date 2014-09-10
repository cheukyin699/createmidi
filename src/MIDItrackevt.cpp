#include <MIDItrackevt.h>

namespace MIDI
{
	unsigned char GPCtype(unsigned short GPC_num)
	{
		if(GPC_num >= 1 && GPC_num <= 4)
			return char((int)Base_GPC + GPC_num - 1);
		else if(GPC_num >= 5 && GPC_num <= 8)
			return char((int)Base_Upper_GPC + GPC_num - 1);
		else
			return (char)0;
	}

	unsigned char Controller_LSB_type(unsigned short cLSB_num)
	{
		if(cLSB_num >= 0 && cLSB_num <= 31)
			return (char)int(Base_Controller_LSB) + cLSB_num;
		else
			return (char)0;
	}

	unsigned char Sound_Controller_type(unsigned short SC_num)
	{
		if(SC_num >= 1 && SC_num <= 10)
			return (char)int(Base_Sound_Controller) + SC_num - 1;
		else
			return (char)0;
	}

	unsigned char Effects_type(unsigned short E_num)
	{
		if(E_num >= 1 && E_num <= 5)
			return (char)int(Base_Effects) + E_num - 1;
		else
			return (char)0;
	}

	unsigned char Mode_Msg_type(unsigned short MM_num)
	{
		if(MM_num >= 1 && MM_num <= 7)
			return (char)int(Base_Mode_Msg) + MM_num - 1;
		else
			return (char)0;
	}
}
