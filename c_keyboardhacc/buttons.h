const char undefined[] = "Undefined";
const char reserved[] = "Reserved";
const char unassigned[] = "Unassigned";
const char OEM_specific[] = "OEM specific";




const char* buttons[] = {
	NULL,						//0x00
	"VK_LBUTTON",				//0x01	Left mouse button
	"VK_RBUTTON",				//0x02	Right mouse button
	"VK_CANCEL",				//0x03	Control - break processing
	"VK_MBUTTON",				//0x04	Middle mouse button(three - button mouse)
	"VK_XBUTTON1",				//0x05	X1 mouse button
	"VK_XBUTTON2",				//0x06	X2 mouse button
	undefined,					//0x07	Undefined
	"VK_BACK",					//0x08	BACKSPACE key
	"VK_TAB",					//0x09	TAB key
	reserved,					//0x0A	Reserved
	reserved,					//0x0B	Reserved
	"VK_CLEAR",					//0x0C	CLEAR key
	"VK_RETURN",				//0x0D	ENTER key
	undefined,					//0x0E 	Undefined
	undefined,					//0x0F	Undefined
	"VK_SHIFT",					//0x10	SHIFT key
	"VK_CONTROL",				//0x11	CTRL key
	"VK_MENU",					//0x12	ALT key
	"VK_PAUSE",					//0x13	PAUSE key
	"VK_CAPITAL",				//0x14	CAPS LOCK key
	"VK_HANGUL",				//0x15	IME Hangul mode
	"VK_IME_ON",				//0x16	IME On
	"VK_JUNJA",					//0x17	IME Junja mode
	"VK_FINAL",					//0x18	IME final mode
	"VK_HANJA",					//0x19	IME Hanja mode
	"VK_IME_OFF",				//0x1A	IME Off
	"VK_ESCAPE",				//0x1B	ESC key
	"VK_CONVERT",				//0x1C	IME convert
	"VK_NONCONVERT",			//0x1D	IME nonconvert
	"VK_ACCEPT",				//0x1E	IME accept
	"VK_MODECHANGE",			//0x1F	IME mode change request
	"VK_SPACE",					//0x20	SPACEBAR
	"VK_PRIOR",					//0x21	PAGE UP key
	"VK_NEXT",					//0x22	PAGE DOWN key
	"VK_END",					//0x23	END key
	"VK_HOME",					//0x24	HOME key
	"VK_LEFT",					//0x25	LEFT ARROW key
	"VK_UP",					//0x26	UP ARROW key
	"VK_RIGHT",					//0x27	RIGHT ARROW key
	"VK_DOWN",					//0x28	DOWN ARROW key
	"VK_SELECT",				//0x29	SELECT key
	"VK_PRINT",					//0x2A	PRINT key
	"VK_EXECUTE",				//0x2B	EXECUTE key
	"VK_SNAPSHOT",				//0x2C	PRINT SCREEN key
	"VK_INSERT",				//0x2D	INS key
	"VK_DELETE",				//0x2E	DEL key
	"VK_HELP",					//0x2F	HELP key
	"0",						//0x30	0 key
	"1",						//0x31	1 key
	"2",						//0x32	2 key
	"3",						//0x33	3 key
	"4",						//0x34	4 key
	"5",						//0x35	5 key
	"6",						//0x36	6 key
	"7",						//0x37	7 key
	"8",						//0x38	8 key
	"9",						//0x39	9 key
	undefined,					//0x3A	Undefined
	undefined,					//0x3B	Undefined
	undefined,					//0x3C	Undefined
	undefined,					//0x3D	Undefined
	undefined,					//0x3E	Undefined
	undefined,					//0x3F	Undefined
	undefined,					//0x40	Undefined
	"A",						//0x41	A key
	"B",						//0x42	B key
	"C",						//0x43	C key
	"D",						//0x44	D key
	"E",						//0x45	E key
	"F",						//0x46	F key
	"G",						//0x47	G key
	"H",						//0x48	H key
	"I",						//0x49	I key
	"J",						//0x4A	J key
	"K",						//0x4B	K key
	"L",						//0x4C	L key
	"M",						//0x4D	M key
	"N",						//0x4E	N key
	"O",						//0x4F	O key
	"P",						//0x50	P key
	"Q",						//0x51	Q key
	"R",						//0x52	R key
	"S",						//0x53	S key
	"T",						//0x54	T key
	"U",						//0x55	U key
	"V",						//0x56	V key
	"W",						//0x57	W key
	"X",						//0x58	X key
	"Y",						//0x59	Y key
	"Z",						//0x5A	Z key
	"VK_LWIN",					//0x5B	Left Windows key(Natural keyboard)
	"VK_RWIN",					//0x5C	Right Windows key(Natural keyboard)
	"VK_APPS",					//0x5D	Applications key(Natural keyboard)
	reserved,					//0x5E	Reserved
	"VK_SLEEP",					//0x5F	Computer Sleep key
	"VK_NUMPAD0",				//0x60	Numeric keypad 0 key
	"VK_NUMPAD1",				//0x61	Numeric keypad 1 key
	"VK_NUMPAD2",				//0x62	Numeric keypad 2 key
	"VK_NUMPAD3",				//0x63	Numeric keypad 3 key
	"VK_NUMPAD4",				//0x64	Numeric keypad 4 key
	"VK_NUMPAD5",				//0x65	Numeric keypad 5 key
	"VK_NUMPAD6",				//0x66	Numeric keypad 6 key
	"VK_NUMPAD7",				//0x67	Numeric keypad 7 key
	"VK_NUMPAD8",				//0x68	Numeric keypad 8 key
	"VK_NUMPAD9",				//0x69	Numeric keypad 9 key
	"VK_MULTIPLY",				//0x6A	Multiply key
	"VK_ADD",					//0x6B	Add key
	"VK_SEPARATOR",				//0x6C	Separator key
	"VK_SUBTRACT",				//0x6D	Subtract key
	"VK_DECIMAL",				//0x6E	Decimal key
	"VK_DIVIDE",				//0x6F	Divide key
	"VK_F1",					//0x70	F1 key
	"VK_F2",					//0x71	F2 key
	"VK_F3",					//0x72	F3 key
	"VK_F4",					//0x73	F4 key
	"VK_F5",					//0x74	F5 key
	"VK_F6",					//0x75	F6 key
	"VK_F7",					//0x76	F7 key
	"VK_F8",					//0x77	F8 key
	"VK_F9",					//0x78	F9 key
	"VK_F10",					//0x79	F10 key
	"VK_F11",					//0x7A	F11 key
	"VK_F12",					//0x7B	F12 key
	"VK_F13",					//0x7C	F13 key
	"VK_F14",					//0x7D	F14 key
	"VK_F15",					//0x7E	F15 key
	"VK_F16",					//0x7F	F16 key
	"VK_F17",					//0x80	F17 key
	"VK_F18",					//0x81	F18 key
	"VK_F19",					//0x82	F19 key
	"VK_F20",					//0x83	F20 key
	"VK_F21",					//0x84	F21 key
	"VK_F22",					//0x85	F22 key
	"VK_F23",					//0x86	F23 key
	"VK_F24",					//0x87	F24 key
	unassigned,					//0x88	Unassigned
	unassigned,					//0x89	Unassigned
	unassigned,					//0x8A	Unassigned
	unassigned,					//0x8B	Unassigned
	unassigned,					//0x8C	Unassigned
	unassigned,					//0x8D	Unassigned
	unassigned,					//0x8E	Unassigned
	unassigned,					//0x8F	Unassigned
	"VK_NUMLOCK",				//0x90	NUM LOCK key
	"VK_SCROLL",				//0x91	SCROLL LOCK key
	OEM_specific,				//0x92	OEM specific
	OEM_specific,				//0x93	OEM specific
	OEM_specific,				//0x94	OEM specific
	OEM_specific,				//0x95	OEM specific
	OEM_specific,				//0x96	OEM specific
	unassigned,					//0x97	Unassigned
	unassigned,					//0x98	Unassigned
	unassigned,					//0x99	Unassigned
	unassigned,					//0x9A	Unassigned
	unassigned,					//0x9B	Unassigned
	unassigned,					//0x9C	Unassigned
	unassigned,					//0x9D	Unassigned
	unassigned,					//0x9E	Unassigned
	unassigned,					//0x9F	Unassigned
	"VK_LSHIFT",				//0xA0	Left SHIFT key
	"VK_RSHIFT",				//0xA1	Right SHIFT key
	"VK_LCONTROL",				//0xA2	Left CONTROL key
	"VK_RCONTROL",				//0xA3	Right CONTROL key
	"VK_LMENU",					//0xA4	Left MENU key
	"VK_RMENU",					//0xA5	Right MENU key
	"VK_BROWSER_BACK",			//0xA6	Browser Back key
	"VK_BROWSER_FORWARD",		//0xA7	Browser Forward key
	"VK_BROWSER_REFRESH",		//0xA8	Browser Refresh key
	"VK_BROWSER_STOP",			//0xA9	Browser Stop key
	"VK_BROWSER_SEARCH",		//0xAA	Browser Search key
	"VK_BROWSER_FAVORITES",		//0xAB	Browser Favorites key
	"VK_BROWSER_HOME",			//0xAC	Browser Start and Home key
	"VK_VOLUME_MUTE",			//0xAD	Volume Mute key
	"VK_VOLUME_DOWN",			//0xAE	Volume Down key
	"VK_VOLUME_UP",				//0xAF	Volume Up key
	"VK_MEDIA_NEXT_TRACK",		//0xB0	Next Track key
	"VK_MEDIA_PREV_TRACK",		//0xB1	Previous Track key
	"VK_MEDIA_STOP",			//0xB2	Stop Media key
	"VK_MEDIA_PLAY_PAUSE",		//0xB3	Play / Pause Media key
	"VK_LAUNCH_MAIL",			//0xB4	Start Mail key
	"VK_LAUNCH_MEDIA_SELECT",	//0xB5	Select Media key
	"VK_LAUNCH_APP1",			//0xB6	Start Application 1 key
	"VK_LAUNCH_APP2",			//0xB7	Start Application 2 key
	reserved,					//0xB8	Reserved
	reserved,					//0xB9	Reserved
	"VK_OEM_1",					//0xBA	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ';:' key
	"VK_OEM_PLUS",				//0xBB	For any country / region, the '+' key
	"VK_OEM_COMMA",				//0xBC	For any country / region, the ',' key
	"VK_OEM_MINUS",				//0xBD	For any country / region, the '-' key
	"VK_OEM_PERIOD",			//0xBE	For any country / region, the '.' key
	"VK_OEM_2",					//0xBF	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '/?' key
	"VK_OEM_3",					//0xC0	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '`~' key
	reserved,					//0xC1	Reserved
	reserved,					//0xC2	Reserved
	reserved,					//0xC3	Reserved
	reserved,					//0xC4	Reserved
	reserved,					//0xC5	Reserved
	reserved,					//0xC6	Reserved
	reserved,					//0xC7	Reserved
	reserved,					//0xC8	Reserved
	reserved,					//0xC9	Reserved
	reserved,					//0xCA	Reserved
	reserved,					//0xCB	Reserved
	reserved,					//0xCC	Reserved
	reserved,					//0xCD	Reserved
	reserved,					//0xCE	Reserved
	reserved,					//0xCF	Reserved
	reserved,					//0xD0	Reserved
	reserved,					//0xD1	Reserved
	reserved,					//0xD2	Reserved
	reserved,					//0xD3	Reserved
	reserved,					//0xD4	Reserved
	reserved,					//0xD5	Reserved
	reserved,					//0xD6	Reserved
	reserved,					//0xD7	Reserved
	unassigned,					//0xD8	Unassigned
	unassigned,					//0xD9	Unassigned
	unassigned,					//0xDA	Unassigned
	"VK_OEM_4",					//0xDB	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '[{' key
	"VK_OEM_5",					//0xDC	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '\|' key
	"VK_OEM_6",					//0xDD	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ']}' key
	"VK_OEM_7",					//0xDE	Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the 'single-quote/double-quote' key
	"VK_OEM_8",					//0xDF	Used for miscellaneous characters; it can vary by keyboard.
	reserved,					//0xE0	Reserved
	OEM_specific,				//0xE1	OEM specific
	"VK_OEM_102",				//0xE2	Either the angle bracket key or the backslash key on the RT 102 - key keyboard
	OEM_specific,				//0xE3	OEM specific
	OEM_specific,				//0xE4	OEM specific
	"VK_PROCESSKEY",			//0xE5	IME PROCESS key
	OEM_specific,				//0xE6	OEM specific
	"VK_PACKET",				//0xE7	Used to pass Unicode characters as if they were keystrokes.The VK_PACKET key is the low word of a 32 - bit Virtual Key value used for non - keyboard input methods.For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN,and WM_KEYUP
	unassigned,					//0xE8	Unassigned
	OEM_specific,				//0xE9	OEM specific
	OEM_specific,				//0xEA	OEM specific
	OEM_specific,				//0xEB	OEM specific
	OEM_specific,				//0xEC	OEM specific
	OEM_specific,				//0xED	OEM specific
	OEM_specific,				//0xEE	OEM specific
	OEM_specific,				//0xEF	OEM specific
	OEM_specific,				//0xF0	OEM specific
	OEM_specific,				//0xF1	OEM specific
	OEM_specific,				//0xF2	OEM specific
	OEM_specific,				//0xF3	OEM specific
	OEM_specific,				//0xF4	OEM specific
	OEM_specific,				//0xF5	OEM specific
	"VK_ATTN",					//0xF6	Attn key
	"VK_CRSEL",					//0xF7	CrSel key
	"VK_EXSEL",					//0xF8	ExSel key
	"VK_EREOF",					//0xF9	Erase EOF key
	"VK_PLAY",					//0xFA	Play key
	"VK_ZOOM",					//0xFB	Zoom key
	"VK_NONAME",				//0xFC	Reserved
	"VK_PA1",					//0xFD	PA1 key
	"VK_OEM_CLEAR",				//0xFE	Clear key
};