#include <windows.h>    //include header files
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define FILE_MENU_ABOUT 99
#define FILE_MENU_EXIT 98
#define EDIT_BGCOLORTXT 97
#define BUTTON_LOGIN 96
#define BUS001 94
#define BUS002 93
#define BUS003 92
#define BUS004 91
#define BUS005 90
#define BUS006 89
#define BUS007 88
#define BUS008 87
#define BUS009 86
#define BUS010 85
#define ECQ 84
#define GCQ 83
#define MECQ 82
#define MGCQ 81
#define TXTCOLOR_OPBUS 80
#define TXTCOLOR_QRTN 79
#define BUTTON_ACCESS 78
#define BUTTON_PROCEED 77
#define BUTTON_GOBACK 76
#define CAPACITY_COLOR 74
#define QTYPE_COLOR 75
#define BUS_FCOLOR 73
#define PCT_COLOR 72
#define ID_RADIOBTN1 71
#define ID_RADIOBTN2 70
#define ID_RADIOBTN3 69
#define FULLY_VACCINATED 68
#define SEMI_VACCINATED 67
#define NOT_VACCINATED 66
#define B0X_1 65
#define B0X_2 64
#define B0X_3 63
#define B0X_4 62
#define B0X_5 61
#define B0X_6 60
#define B0X_7 59
#define B0X_8 58
#define B0X_9 57
#define B0X_10 56
#define B0X_11 55
#define B0X_12 54
#define B0X_13 53
#define B0X_14 52
#define B0X_15 51
#define B0X_16 50
#define B0X_17 49
#define B0X_18 48
#define B0X_19 47
#define B0X_20 46
#define B0X_21 45
#define B0X_22 44
#define B0X_23 43
#define LOG_OUT 42

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);   //function prototypes
void AddControls(HWND);
void AddMenus(HWND);
void loadImages();
void registerWindowProcedure2(HINSTANCE);
void registerWindowProcedure3(HINSTANCE);
void registerWindowProcedure4(HINSTANCE);
void registerWindowProcedureGCQ(HINSTANCE);
void registerWindowProcedureMGCQ(HINSTANCE);
void registerWindowProcedureECQ(HINSTANCE);
void registerWindowProcedureMECQ(HINSTANCE);
void registerWindowProcedureAccessDB(HINSTANCE);
void registerWindowProcedurePassInfo(HINSTANCE);
void registerWindowProcedureADataBase(HINSTANCE);
void registerWindowProcedureADataBaseW(HINSTANCE);
void registerWindowProcedureADataBaseM(HINSTANCE);
void displayWindowProcedure2(HWND);
void displayWindowProcedure3(HWND);
void displayWindowProcedure4(HWND);
void displayWindowProcedureGCQ(HWND);
void displayWindowProcedureMGCQ(HWND);
void displayWindowProcedureECQ(HWND);
void displayWindowProcedureMECQ(HWND);
void displayWindowProcedureAccessDB(HWND);
void displayWindowProcedurePassInfo(HWND);
void displayWindowProcedureADataBase(HWND);
void displayWindowProcedureADataBaseW(HWND);
void displayWindowProcedureADataBaseM(HWND);
void AddWinProc2(HWND);
void AddWinProc3(HWND);
void AddWinProc4(HWND);
void AddWinProcGCQ(HWND);
void AddWinProcMGCQ(HWND);
void AddWinProcECQ(HWND);
void AddWinProcMECQ(HWND);
void AddWinProcAccessDB(HWND);
void AddWinProcPassInfo(HWND);
void AddWinProcADataBase(HWND);
void AddWinProcADataBaseW(HWND);
void AddWinProcADataBaseM(HWND);
void open_file(HWND);
void open_fileW(HWND);
void open_fileM(HWND);

HMENU hMenu;
HWND hLogo, hIconLogin, hSFontEnter, hPassword, hLoginWindow, hSecWindow, hInitialWindow, hThirdWindow, hAccessDBWindow, hGCQWindow, hMGCQWindow, hECQWindow, hMECQWindow, hPassInfoWindow, hADataBaseWindow, hADataBaseWWindow, hADataBaseMWindow, 
		hECQ, hGCQ, hMECQ, hMGCQ, hSelectOpBus, hCheckBG, hTypeQ, hPercentage, hQStore, hVaccStatus,
		hBus001, hBus002, hBus003, hBus004, hBus005, hBus006, hBus007, hBus008, hBus009, hBus010, 
		hPassInfo, hName, hAddress, hContact, hNameEdit, hAddressEdit, hContactEdit, hFullyV, hSemiV, 
		hNotV, hPickUp, hStatic, hDropOff, hBusChoice, hCapacity, hDaily, hWeekly, hMonthly, hwhichAccess,
		hBus001R, hBus002R, hBus003R, hBus004R, hBus005R, hBus006R, hBus007R, hBus008R, hBus009R, hBus010R, hBus, hBody;

//Handler for Gboxes
HWND hGBox1, hGBox2, hGBox3, hGBox4, hGBox5, hGBox6, hGBox7, hGBox8, hGBox9, hGBox10, hGBox11,
    hGBox12, hGBox13, hGBox14, hGBox15, hGBox16, hGBox17, hGBox18, hGBox19, hGBox20, hGBox21, hGBox22, hGBox23, hSeatNo;

HWND hQClass, hQClassStat, hBusNum, hBusNumStat, hSeatNum, hSeatNumStat, hVaccStat, hVaccStatStat,
            hNameStat, hAddressStat, hContactStat, hPickUpP, hPickUpStat, hDropOffP, hDropOffStat;

HBITMAP bLogo, bIconLogin, bLogin, bCheckBG, bAccess, bProceed, bGoBack, bGCQBus;
HBRUSH hbrBkgnd;
HFONT hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
		      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
		      
UINT t;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){     //creating the parent window


    WNDCLASSW wc = {0};         //creating the window class
	HBRUSH hb = ::CreateSolidBrush(RGB(255, 235, 170));

    wc.hbrBackground = hb; //background color
    
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);  //window cursor
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";        //defining class name
    wc.lpfnWndProc = WindowProcedure;           //calling window procedure

    if(!RegisterClassW(&wc))
        return -1;
        
    registerWindowProcedure2(hInst);
    registerWindowProcedure3(hInst);
    registerWindowProcedure4(hInst);
    registerWindowProcedureGCQ(hInst);
    registerWindowProcedureMGCQ(hInst);
    registerWindowProcedureECQ(hInst);
    registerWindowProcedureMECQ(hInst);
    registerWindowProcedureAccessDB(hInst);
    registerWindowProcedurePassInfo(hInst);
    registerWindowProcedureADataBase(hInst);
    registerWindowProcedureADataBaseW(hInst);
    registerWindowProcedureADataBaseM(hInst);

    hLoginWindow = CreateWindowW(L"myWindowClass", L"EdsaXpress", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_LEFT | WS_MINIMIZEBOX,
                  500, 100, 300, 350, NULL, NULL, NULL, NULL);   //parent window

    MSG msg = {0};

    while(GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
	
	int mbVal;
	char pass[100];
	switch(msg){
        case WM_COMMAND:
            switch(wp){

            case BUTTON_LOGIN:
            	GetWindowText(hPassword, pass, 100);
            	if (strcmp(pass, "admin") == 0){
            		displayWindowProcedure2(hWnd);
            		ShowWindow(hLoginWindow, SW_HIDE);	
				}
				else{
            		MessageBoxW(hWnd, L"Invalid Password!\nPlease check your inputs", L"Password Error", MB_OK | MB_ICONEXCLAMATION);		
				}
		
            	break;
			case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
			}
		break;

		case WM_CTLCOLOREDIT:{
			
		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(255,254,254));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(208, 219, 232));
            }
            return (INT_PTR)hbrBkgnd;
		}break;
		
		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));
            SetBkMode(hdcStatic,TRANSPARENT);
            
                
            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            
            return (INT_PTR)hbrBkgnd;
        }break;

		
		case WM_CREATE:        //executed once the window is created
	        loadImages();
	        AddMenus(hWnd);
	        AddControls(hWnd);
	        break;
		case WM_DESTROY:       //exiting session
	        PostQuitMessage(0);
	        break;
	    default:
	    	return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddMenus(HWND hWnd){       //add menu function that accepts the window handler as the parameter

    hMenu = CreateMenu();       //creating menus using HMENU

    AppendMenu(hMenu, MF_STRING, FILE_MENU_ABOUT, "About");     //menus
    AppendMenu(hMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

    SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd){
	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  35, 35, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    
    hIconLogin = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  110, 105, 70, 70, hWnd, NULL, NULL, NULL);
    SendMessage(hIconLogin, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bIconLogin);
    
    HFONT hFontInside = CreateFont (17, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
    
    hSFontEnter = CreateWindowW(L"Static", L"Enter Password:", WS_VISIBLE | WS_CHILD | SS_CENTER,
                  62, 175, 160, 140, hWnd, (HMENU)EDIT_BGCOLORTXT, NULL, NULL);
    SendMessage(hSFontEnter, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hPassword = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_CENTER | ES_PASSWORD | WS_BORDER,
                  60, 200, 160, 20, hWnd, NULL, NULL, NULL);
                  
    HWND hLoginB = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  97, 230, 80, 20, hWnd, (HMENU)BUTTON_LOGIN, NULL, NULL);
    SendMessageW(hLoginB, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogin);
    
   
}

void loadImages(){
	bLogo = (HBITMAP)LoadImageW(NULL, L"B-EdsaXpress.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bIconLogin = (HBITMAP)LoadImageW(NULL, L"B-Login_Logo.bmp", IMAGE_BITMAP, 70, 70, LR_LOADFROMFILE);
	bLogin = (HBITMAP)LoadImageW(NULL, L"B-login_button.bmp", IMAGE_BITMAP, 80, 20, LR_LOADFROMFILE);
	bAccess = (HBITMAP)LoadImageW(NULL, L"B-Access.bmp", IMAGE_BITMAP, 110, 25, LR_LOADFROMFILE);
	bProceed = (HBITMAP)LoadImageW(NULL, L"B-Proceed.bmp", IMAGE_BITMAP, 110, 23, LR_LOADFROMFILE);
	bGoBack = (HBITMAP)LoadImageW(NULL, L"B-Go_Back.bmp", IMAGE_BITMAP, 110, 23, LR_LOADFROMFILE);
	bGCQBus = (HBITMAP)LoadImageW(NULL, L"B-BusSeats.bmp", IMAGE_BITMAP, 660, 250, LR_LOADFROMFILE);
	
}

//--------------------------------------------------------------- 2ND WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedure2(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){
	
	int mbVal;
	bool checked = false;
	static int flag = 0, qFlag = 0;
	switch(msg){
		rescan:
		case WM_COMMAND:
			//1
			if (LOWORD(wp) == BUS001){
				checked = IsDlgButtonChecked(hWnd, BUS001);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS001, BST_CHECKED);
	                SetWindowText(hBus001, "Operational");
	                flag = 1;
	            } else {
	            	CheckDlgButton(hWnd, BUS001, BST_UNCHECKED);
	            	SetWindowText(hBus001, "BUS 001");
	            	flag = 0;
	            }
			}
			
            //2
            if (LOWORD(wp) == BUS002){
				checked = IsDlgButtonChecked(hWnd, BUS002);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS002, BST_CHECKED);
	                SetWindowText(hBus002, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS002, BST_UNCHECKED);
	               SetWindowText(hBus002, "BUS 002");
	               flag = 0;
	            }
			}
			
            //3
            if (LOWORD(wp) == BUS003){
				checked = IsDlgButtonChecked(hWnd, BUS003);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS003, BST_CHECKED);
	                SetWindowText(hBus003, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS003, BST_UNCHECKED);
	               SetWindowText(hBus003, "BUS 003");
	               flag = 0;
	            }
			}
            //4
            if (LOWORD(wp) == BUS004){
				checked = IsDlgButtonChecked(hWnd, BUS004);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS004, BST_CHECKED);
	                SetWindowText(hBus004, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS004, BST_UNCHECKED);
	               SetWindowText(hBus004, "BUS 004");
	               flag = 0;
	            }
			}
			//5
            if (LOWORD(wp) == BUS005){
				checked = IsDlgButtonChecked(hWnd, BUS005);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS005, BST_CHECKED);
	                SetWindowText(hBus005, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS005, BST_UNCHECKED);
	               SetWindowText(hBus005, "BUS 005");
	               flag = 0;
	            }
			}
            //6
            if (LOWORD(wp) == BUS006){
				checked = IsDlgButtonChecked(hWnd, BUS006);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS006, BST_CHECKED);
	                SetWindowText(hBus006, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS006, BST_UNCHECKED);
	               SetWindowText(hBus006, "BUS 006");
	               flag = 0;
	            }
			}
            //7
            if (LOWORD(wp) == BUS007){
				checked = IsDlgButtonChecked(hWnd, BUS007);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS007, BST_CHECKED);
	                SetWindowText(hBus007, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS007, BST_UNCHECKED);
	               SetWindowText(hBus007, "BUS 007");
	               flag = 0;
	            }
			}
            //8
            if (LOWORD(wp) == BUS008){
				checked = IsDlgButtonChecked(hWnd, BUS008);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS008, BST_CHECKED);
	                SetWindowText(hBus008, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS008, BST_UNCHECKED);
	               SetWindowText(hBus008, "BUS 008");
	               flag = 0;
	            }
			}
            //9
            if (LOWORD(wp) == BUS009){
				checked = IsDlgButtonChecked(hWnd, BUS009);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS009, BST_CHECKED);
	                SetWindowText(hBus009, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS009, BST_UNCHECKED);
	               SetWindowText(hBus009, "BUS 009");
	               flag = 0;
	            }
			}
            //10
            if (LOWORD(wp) == BUS010){
				checked = IsDlgButtonChecked(hWnd, BUS010);
	            if (!checked) {
	                CheckDlgButton(hWnd, BUS010, BST_CHECKED);
	                SetWindowText(hBus010, "Operational");
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, BUS010, BST_UNCHECKED);
	               SetWindowText(hBus010, "BUS 010");
	               flag = 0;
	            }
			}
			if (LOWORD(wp) == ECQ){
				SetWindowText(hQStore, "ECQ");
				qFlag = 1;
			}

			if (LOWORD(wp) == MECQ){
				SetWindowText(hQStore, "MECQ");
				qFlag = 1;
			}
			if (LOWORD(wp) == GCQ){
				SetWindowText(hQStore, "GCQ");
				qFlag = 1;
			}
			if (LOWORD(wp) == MGCQ){
				SetWindowText(hQStore, "MGCQ");
				qFlag = 1;
			}
            
            
            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_ACCESS:
            		displayWindowProcedureAccessDB(hWnd);
					ShowWindow(hInitialWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:
					if (flag == 1 && qFlag == 1) {
						ShowWindow(hInitialWindow, SW_HIDE);
						displayWindowProcedure3(hWnd);
					}
					else if (flag == 0 || qFlag == 0){
						MessageBoxW(hWnd, L"Please fill up all fields\n\tor\nRemoval of Data Recorded\n\n     Please try again!", L"Input Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
					}
					break;
			}
		break; 
		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(164, 199, 241));
            SetBkMode(hdcStatic,TRANSPARENT);
            
            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));
                hbrBkgnd = CreateSolidBrush(RGB(189,219,255));
			}
                
            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            
            return (INT_PTR)hbrBkgnd;
            
        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{
		  	
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProc2(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedure2(HINSTANCE hInst){

	
	WNDCLASSW dialog = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255, 235, 170));

    dialog.hbrBackground = hb;
    dialog.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialog.hInstance = hInst;
    dialog.lpszClassName = L"WindProc2";
    dialog.lpfnWndProc = WindowProcedure2;

    RegisterClassW(&dialog);
    
}

void displayWindowProcedure2(HWND hWnd){

    hInitialWindow = CreateWindowW(L"WindProc2", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 340, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProc2(HWND hWnd){
	
	
	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                60, 15, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    
    HFONT hFontInside = CreateFont (17, 0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
      
    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 90, 230, 150, hWnd, NULL, NULL, NULL);
    
    hSelectOpBus = CreateWindowW(L"Static", L" Select Operational Buses", WS_VISIBLE | WS_CHILD | WS_BORDER,
                68, 85, 200, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hSelectOpBus, WM_SETFONT, (LPARAM)hFontInside, TRUE);
                
    hBus001 = CreateWindowW(L"button", L"BUS 001", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                60, 110, 100, 25, hWnd, (HMENU)BUS001, NULL, NULL);
    CheckDlgButton(hWnd, 1, BST_UNCHECKED);
    hBus002 = CreateWindowW(L"button", L"BUS 002", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                60, 135, 100, 25, hWnd, (HMENU)BUS002, NULL, NULL);
    CheckDlgButton(hWnd, 2, BST_UNCHECKED);
    hBus003 = CreateWindowW(L"button", L"BUS 003", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                60, 160, 100, 25, hWnd, (HMENU)BUS003, NULL, NULL);
    CheckDlgButton(hWnd, 3, BST_UNCHECKED);
    hBus004 = CreateWindowW(L"button", L"BUS 004", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                60, 185, 100, 25, hWnd, (HMENU)BUS004, NULL, NULL);
    CheckDlgButton(hWnd, 4, BST_UNCHECKED);
    hBus005 = CreateWindowW(L"button", L"BUS 005", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                60, 210, 100, 25, hWnd, (HMENU)BUS005, NULL, NULL);
    CheckDlgButton(hWnd, 5, BST_UNCHECKED);
    
    hBus006 = CreateWindowW(L"button", L"BUS 006", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                175, 110, 100, 25, hWnd, (HMENU)BUS006, NULL, NULL);
    CheckDlgButton(hWnd, 6, BST_UNCHECKED);
    hBus007 = CreateWindowW(L"button", L"BUS 007", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                175, 135, 100, 25, hWnd, (HMENU)BUS007, NULL, NULL);
    CheckDlgButton(hWnd, 7, BST_UNCHECKED);
    hBus008 = CreateWindowW(L"button", L"BUS 008", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                175, 160, 100, 25, hWnd, (HMENU)BUS008, NULL, NULL);
    CheckDlgButton(hWnd, 8, BST_UNCHECKED);
    hBus009 = CreateWindowW(L"button", L"BUS 009", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                175, 185, 100, 25, hWnd, (HMENU)BUS009, NULL, NULL);
    CheckDlgButton(hWnd, 9, BST_UNCHECKED);
    hBus010 = CreateWindowW(L"button", L"BUS 010", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                175, 210, 100, 25, hWnd, (HMENU)BUS010, NULL, NULL);
    CheckDlgButton(hWnd, 10, BST_UNCHECKED);
    
    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 255, 230, 65, hWnd, NULL, NULL, NULL);
    hSelectOpBus = CreateWindowW(L"Static", L" Select Type of Quarantine ", WS_VISIBLE | WS_CHILD | WS_BORDER,
                63, 248, 205, 20, hWnd, (HMENU)TXTCOLOR_QRTN, NULL, NULL);
    SendMessage(hSelectOpBus, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hECQ = CreateWindowW(L"Button", L"ECQ", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                  70, 270, 80, 20, hWnd, (HMENU)ECQ, NULL, NULL);
    hGCQ = CreateWindowW(L"Button", L"GCQ", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                  70, 295, 80, 20, hWnd, (HMENU)GCQ, NULL, NULL);
    hMECQ = CreateWindowW(L"Button", L"MECQ", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                  190, 270, 80, 20, hWnd, (HMENU)MECQ, NULL, NULL);
    hMGCQ = CreateWindowW(L"Button", L"MGCQ", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON ,
                  190, 295, 80, 20, hWnd, (HMENU)MGCQ, NULL, NULL);
    
    
	HWND hAccess = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_ACCESS, NULL, NULL);
    SendMessageW(hAccess, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bAccess);
    
    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  190, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);
    
    hQStore = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                63, 500, 205, 20, hWnd, (HMENU)TXTCOLOR_QRTN, NULL, NULL);
}

//--------------------------------------------------------------- 3RD WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedure3(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){
	
	int mbVal;
	static int flag = 0;
	switch(msg){
		case WM_COMMAND:
			
            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUS001:
            		SetWindowText(hBusChoice, "BUS 001");
            		flag = 1;
            		break;
            	case BUS002:
            		SetWindowText(hBusChoice, "BUS 002");
            		flag = 1;
            		break;
            	case BUS003:
            		SetWindowText(hBusChoice, "BUS 003");
            		flag = 1;
            		break;
            	case BUS004:
            		SetWindowText(hBusChoice, "BUS 004");
            		flag = 1;
            		break;
            	case BUS005:
            		SetWindowText(hBusChoice, "BUS 005");
            		flag = 1;
            		break;
            	case BUS006:
            		SetWindowText(hBusChoice, "BUS 006");
            		flag = 1;
            		break;
            	case BUS007:
            		SetWindowText(hBusChoice, "BUS 007");
            		flag = 1;
            		break;
            	case BUS008:
            		SetWindowText(hBusChoice, "BUS 008");
            		flag = 1;
            		break;
            	case BUS009:
            		SetWindowText(hBusChoice, "BUS 009");
            		flag = 1;
            		break;
            	case BUS010:
            		SetWindowText(hBusChoice, "BUS 010");
            		flag = 1;
            		break;
            	case BUTTON_GOBACK:
            		ShowWindow(hInitialWindow, SW_SHOW);
            		ShowWindow(hSecWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:
					if (flag == 1) {
						displayWindowProcedure4(hWnd);
						ShowWindow(hSecWindow, SW_HIDE);
					}
					else if (flag == 0){
						MessageBoxW(hWnd, L"Please fill up all fields!", L"Input Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
					}
					break;
					
			}
		break;
		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(164, 199, 241));
            SetBkMode(hdcStatic,TRANSPARENT);
            
            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));
				hbrBkgnd = CreateSolidBrush(RGB(189,219,255));}
            if (GetDlgItem(hWnd, QTYPE_COLOR) == (HWND)lp || GetDlgItem(hWnd, CAPACITY_COLOR) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 112, 0));}
            if (GetDlgItem(hWnd, BUS_FCOLOR) == (HWND)lp || GetDlgItem(hWnd, PCT_COLOR) == (HWND)lp){
			 SetTextColor(hdcStatic, RGB(210, 34, 45));}
                
            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            
            return (INT_PTR)hbrBkgnd;
            
        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	        
	    case WM_CREATE:
	    	AddMenus(hWnd);
	        loadImages();
	        AddWinProc3(hWnd);
	        break;
	        
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedure3(HINSTANCE hInst){
	
	WNDCLASSW dialogSec = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255, 235, 170));

    dialogSec.hbrBackground = hb;
    dialogSec.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogSec.hInstance = hInst;
    dialogSec.lpszClassName = L"WindProc3";
    dialogSec.lpfnWndProc = WindowProcedure3;

    RegisterClassW(&dialogSec);
    
}

void displayWindowProcedure3(HWND hWnd){

    hSecWindow = CreateWindowW(L"WindProc3", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 340, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProc3(HWND hWnd){
	char checkOP[100];

	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                60, 15, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    
    HFONT hFontInside = CreateFont (16, 0, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
    
    HFONT hFontInside2 = CreateFont (17, 0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
    
    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 90, 230, 150, hWnd, NULL, NULL, NULL);
    
    hSelectOpBus = CreateWindowW(L"Static", L"Select Bus", WS_VISIBLE | WS_CHILD| SS_CENTER | WS_BORDER,
                115, 85, 100, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hSelectOpBus, WM_SETFONT, (LPARAM)hFontInside2, TRUE);
                
    hBus001R = CreateWindowW(L"button", L"BUS 001", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                60, 105, 100, 35, hWnd, (HMENU)BUS001, NULL, NULL);
    CheckDlgButton(hWnd, 1, BST_UNCHECKED);
	GetWindowText (hBus001, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus001R, TRUE);
	} else {
		EnableWindow(hBus001R, FALSE);
	}
    hBus002R = CreateWindowW(L"button", L"BUS 002", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                60, 130, 100, 35, hWnd, (HMENU)BUS002, NULL, NULL);
    CheckDlgButton(hWnd, 2, BST_UNCHECKED);
    GetWindowText (hBus002, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus002R, TRUE);
	} else {
		EnableWindow(hBus002R, FALSE);
	}
    hBus003R = CreateWindowW(L"button", L"BUS 003", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                60, 155, 100, 35, hWnd, (HMENU)BUS003, NULL, NULL);
    CheckDlgButton(hWnd, 3, BST_UNCHECKED);
    GetWindowText (hBus003, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus003R, TRUE);
	} else {
		EnableWindow(hBus003R, FALSE);
	}
    hBus004R = CreateWindowW(L"button", L"BUS 004", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                60, 180, 100, 35, hWnd, (HMENU)BUS004, NULL, NULL);
    CheckDlgButton(hWnd, 4, BST_UNCHECKED);
    GetWindowText (hBus004, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus004R, TRUE);
	} else {
		EnableWindow(hBus004R, FALSE);
	}
    hBus005R = CreateWindowW(L"button", L"BUS 005", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                60, 205, 100, 30, hWnd, (HMENU)BUS005, NULL, NULL);
    CheckDlgButton(hWnd, 5, BST_UNCHECKED);
    GetWindowText (hBus005, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus005R, TRUE);
	} else {
		EnableWindow(hBus005R, FALSE);
	}
	
    hBus006R = CreateWindowW(L"button", L"BUS 006", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                190, 105, 80, 35, hWnd, (HMENU)BUS006, NULL, NULL);
    CheckDlgButton(hWnd, 6, BST_UNCHECKED);
    GetWindowText (hBus006, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus006R, TRUE);
	} else {
		EnableWindow(hBus006R, FALSE);
	}
    hBus007R = CreateWindowW(L"button", L"BUS 007", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                190, 130, 80, 35, hWnd, (HMENU)BUS007, NULL, NULL);
    CheckDlgButton(hWnd, 7, BST_UNCHECKED);
    GetWindowText (hBus007, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus007R, TRUE);
	} else {
		EnableWindow(hBus007R, FALSE);
	}
    hBus008R = CreateWindowW(L"button", L"BUS 008", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                190, 155, 80, 35, hWnd, (HMENU)BUS008, NULL, NULL);
    CheckDlgButton(hWnd, 8, BST_UNCHECKED);
    GetWindowText (hBus008, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus008R, TRUE);
	} else {
		EnableWindow(hBus008R, FALSE);
	}
    hBus009R = CreateWindowW(L"button", L"BUS 009", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                190, 180, 80, 35, hWnd, (HMENU)BUS009, NULL, NULL);
    CheckDlgButton(hWnd, 9, BST_UNCHECKED);
    GetWindowText (hBus009, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus009R, TRUE);
	} else {
		EnableWindow(hBus009R, FALSE);
	}
    hBus010R = CreateWindowW(L"button", L"BUS 010", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                190, 205, 80, 30, hWnd, (HMENU)BUS010, NULL, NULL);
    CheckDlgButton(hWnd, 10, BST_UNCHECKED);
    GetWindowText (hBus010, checkOP, 100);
	if (strcmp(checkOP, "Operational") == 0){
		EnableWindow(hBus010R, TRUE);
	} else {
		EnableWindow(hBus010R, FALSE);
	}
    
    hCheckBG = CreateWindowW(L"Static", L"The seating capacity of a bus under \nis", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                50, 255, 230, 65, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
     SendMessage(hCheckBG, WM_SETFONT, (LPARAM)hFontInside, TRUE);
     
    hTypeQ = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_CENTER,
                103, 275, 50, 18, hWnd, (HMENU)QTYPE_COLOR, NULL, NULL);
    SendMessage(hTypeQ, WM_SETFONT, (LPARAM)hFontTypeQ, TRUE);
    
    hPercentage = CreateWindow("Static", "" , WS_VISIBLE | WS_CHILD | WS_BORDER|SS_CENTER,
		                185, 275, 50, 18, hWnd, NULL, NULL, NULL);
    
	SendMessage(hPercentage, WM_SETFONT, (LPARAM)hFontTypeQ, TRUE);
	
	hBusChoice = CreateWindowW(L"Static", L"BUS", WS_VISIBLE | WS_CHILD | SS_CENTER,
                65, 297, 65, 18, hWnd, (HMENU)BUS_FCOLOR, NULL, NULL);
    SendMessage(hBusChoice, WM_SETFONT, (LPARAM)hFontTypeQ, TRUE);
    
    HWND txt = CreateWindowW(L"Static", L"'s capacity is ", WS_VISIBLE | WS_CHILD | SS_CENTER,
                120, 297, 105, 18, hWnd, NULL, NULL, NULL);
    SendMessage(txt, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hCapacity = CreateWindow("Static", "", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
                213, 297, 40, 18, hWnd, (HMENU)CAPACITY_COLOR, NULL, NULL);
    SendMessage(hCapacity, WM_SETFONT, (LPARAM)hFontTypeQ, TRUE);
    
    
    char Qtype[100];
	GetWindowText(hQStore, Qtype, 100);
    
    if (strcmp(Qtype, "ECQ") == 0){
    	SetWindowText(hTypeQ, "ECQ");
		hPercentage = CreateWindowW(L"Static", L"25%" , WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 185, 275, 50, 18, hWnd, (HMENU)PCT_COLOR, NULL, NULL);
		SetWindowText(hCapacity, "11");
	}
	else if (strcmp(Qtype, "MECQ") == 0){
		SetWindowText(hTypeQ, "MECQ");
		hPercentage = CreateWindowW(L"Static", L"35%" , WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 185, 275, 50, 18, hWnd, (HMENU)PCT_COLOR, NULL, NULL);
		SetWindowText(hCapacity, "14");
	}
	else if (strcmp(Qtype, "GCQ") == 0){\
		SetWindowText(hTypeQ, "GCQ");
		hPercentage = CreateWindowW(L"Static", L"50%" , WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 185, 275, 50, 18, hWnd, (HMENU)PCT_COLOR, NULL, NULL);
		SetWindowText(hCapacity, "21");
	}	
	else if (strcmp(Qtype, "MGCQ") == 0){
		SetWindowText(hTypeQ, "MGCQ");
		hPercentage = CreateWindowW(L"Static", L"75%" , WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 185, 275, 50, 18, hWnd, (HMENU)PCT_COLOR, NULL, NULL);
		SetWindowText(hCapacity, "23");
	}
			
	HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);
    
    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  190, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);
}


//--------------------------------------------------------------- 4TH WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedure4(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;
	const wchar_t *items[] = { L"North Avenue", L"Cubao", L"Guadalupe", L"Magallanes", L"SM MOA", L"PITX"};
	char name[100], address[100], contact[100], pickUp[100], dropOff[100], typeQ[100];
	static int flag = 0;
	switch(msg){

        case WM_COMMAND:
            if ( HIWORD(wp) == CBN_SELCHANGE) {
                LRESULT selPick = SendMessage(hPickUp, CB_GETCURSEL, 0, 0);
                LRESULT selDrop = SendMessage(hDropOff, CB_GETCURSEL, 0, 0);
                SetFocus(hWnd);
            }

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case FULLY_VACCINATED:
            		SetWindowText(hVaccStatus, "Fully Vaccinated");
            		flag = 1;
            		break;
            	case SEMI_VACCINATED:
            		SetWindowText(hVaccStatus, "Semi-Vaccinated");
            		flag = 1;
            		break;
            	case NOT_VACCINATED:
            		SetWindowText(hVaccStatus, "Not Vaccinated");
            		flag =1;
            		break;
            	case BUTTON_GOBACK:
            		ShowWindow(hThirdWindow, SW_HIDE);
            		ShowWindow(hSecWindow, SW_SHOW);
					break;
				case BUTTON_PROCEED:
					GetWindowText(hNameEdit, name, 100);
					GetWindowText(hAddressEdit, address, 100);
					GetWindowText(hContactEdit, contact, 100);
					GetWindowText(hPickUp, pickUp, 100);
					GetWindowText(hDropOff, dropOff, 100);
					
					if (strcmp(name, "") == 0 || strcmp(address, "") == 0 || strcmp(contact, "") == 0 || flag != 1){
						MessageBoxW(hWnd, L"Please fill up all fields!", L"Input Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
					}
					else if (strcmp(pickUp, "Pick Up Point") == 0 || strcmp(dropOff, "Drop Off Point") == 0){
						MessageBoxW(hWnd, L"Please Select Pick Up and Drop Off Point!", L"Selection Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
					}
					else {
						ShowWindow(hThirdWindow, SW_HIDE);
					}
					
					GetWindowText(hTypeQ, typeQ, 100);
					if (strcmp(typeQ, "ECQ") == 0){
						displayWindowProcedureECQ(hWnd);
					}
					else if (strcmp(typeQ, "MECQ") == 0){
						displayWindowProcedureMECQ(hWnd);
					}
					else if (strcmp(typeQ, "GCQ") == 0){
						displayWindowProcedureGCQ(hWnd);
					}
					else if (strcmp(typeQ, "MGCQ") == 0){
						displayWindowProcedureMGCQ(hWnd);
					}
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(164, 199, 241));
            SetBkMode(hdcStatic,TRANSPARENT);
            
            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));
				hbrBkgnd = CreateSolidBrush(RGB(189,219,255));}

                
            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            
            return (INT_PTR)hbrBkgnd;
            
        }break;

		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{

	        HFONT hFontInside = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
              OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
              DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

            hPickUp = CreateWindowW(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
                           50, 210, 115, 150, hWnd, NULL, NULL, NULL);
            SetWindowText(hPickUp, "Pick Up Point");
            SendMessage(hPickUp, WM_SETFONT, (LPARAM)hFontInside, TRUE);

            for (int i = 0; i < 6; i++ )
            {
                SendMessageW(hPickUp, CB_ADDSTRING, 0, (LPARAM) items[i]);
            }

            hDropOff = CreateWindowW(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
                           168, 210, 115, 150, hWnd, NULL, NULL, NULL);
            SetWindowText(hDropOff, "Drop Off Point");
            SendMessage(hDropOff, WM_SETFONT, (LPARAM)hFontInside, TRUE);

            for (int i = 0; i < 6; i++ )
            {
                SendMessageW(hDropOff, CB_ADDSTRING, 0, (LPARAM) items[i]);
            }

	        AddMenus(hWnd);
	        loadImages();
	        AddWinProc4(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedure4(HINSTANCE hInst){

	WNDCLASSW dialogThird = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255, 235, 170));

    dialogThird.hbrBackground = hb;
    dialogThird.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogThird.hInstance = hInst;
    dialogThird.lpszClassName = L"WindProc4";
    dialogThird.lpfnWndProc = WindowProcedure4;

    RegisterClassW(&dialogThird);

}

void displayWindowProcedure4(HWND hWnd){

    hThirdWindow = CreateWindowW(L"WindProc4", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 340, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProc4(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                60, 15, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (18, 0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                50, 90, 230, 110, hWnd, NULL, NULL, NULL);

    hPassInfo = CreateWindowW(L"Static", L"Passenger Information", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER,
                65, 85, 200, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hName = CreateWindowW(L"Static", L"Name: ", WS_VISIBLE | WS_CHILD | SS_LEFT,
                65, 120, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hName, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hNameEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER | ES_AUTOHSCROLL,
                120, 120, 150, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hNameEdit, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hAddress = CreateWindowW(L"Static", L"Address: ", WS_VISIBLE | WS_CHILD| SS_LEFT,
                65, 145, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hAddress, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hAddressEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT | WS_BORDER |ES_AUTOHSCROLL,
                120, 145, 150, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hAddressEdit, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hContact = CreateWindowW(L"Static", L"Contact: ", WS_VISIBLE | WS_CHILD| SS_LEFT,
                65, 170, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hContact, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hContactEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | SS_LEFT| WS_BORDER | ES_AUTOHSCROLL,
                120, 170, 150, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hContactEdit, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                50, 245, 230, 80, hWnd, NULL, NULL, NULL);
    SendMessage(hCheckBG, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hFullyV = CreateWindowW(L"Button", L"Fully Vaccinated", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                110, 250, 125, 20, hWnd, (HMENU)FULLY_VACCINATED, NULL, NULL);
    SendMessage(hFullyV, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hSemiV = CreateWindowW(L"Button", L"Semi Vaccinated", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                110, 275, 125, 20, hWnd, (HMENU)SEMI_VACCINATED, NULL, NULL);
    SendMessage(hSemiV, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hNotV = CreateWindowW(L"Button", L"Not Vaccinated", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                110, 300, 125, 20, hWnd, (HMENU)NOT_VACCINATED, NULL, NULL);
    SendMessage(hNotV, WM_SETFONT, (LPARAM)hFontInfo, TRUE);


	HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  190, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

	hVaccStatus = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                50, 500, 230, 80, hWnd, NULL, NULL, NULL);
}

//--------------------------------------------------------------- ACCESSDB WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccessDB(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	
	switch(msg){
		
		int mbLog;
		static int btnStatus;
		
        case WM_COMMAND:
		
			switch(wp){
				
				case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
				
				case LOG_OUT:{
	                    mbLog = MessageBox(hWnd, "Log-out?", "Log Out", MB_YESNO|MB_ICONEXCLAMATION);
	                    if (mbLog==IDYES)
	                        {ShowWindow(hLoginWindow, SW_SHOW);
	                        ShowWindow(hInitialWindow, SW_HIDE);}
	                    else if (mbLog==IDNO)
                        	return 0;
                        }break;
				case ID_RADIOBTN1: 
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "1"); }
		        	break;
		        case ID_RADIOBTN2: 
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "2"); }
		        	break;
		        case ID_RADIOBTN3: 
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "3"); }
		        	break;
            	case BUTTON_GOBACK:
            		ShowWindow(hAccessDBWindow, SW_HIDE);
            		ShowWindow(hInitialWindow, SW_SHOW);
					break;
				case BUTTON_PROCEED:
					
					char get[100];
					GetWindowText(hwhichAccess, get, 100);
					if (strcmp(get, "1") == 0){
						displayWindowProcedureADataBase(hWnd);
					}
					if (strcmp(get, "2") == 0){
						displayWindowProcedureADataBaseW(hWnd);
					}
					if (strcmp(get, "3") == 0){
						displayWindowProcedureADataBaseM(hWnd);
					}
					ShowWindow(hAccessDBWindow, SW_HIDE);	
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(164, 199, 241));
            SetBkMode(hdcStatic,TRANSPARENT);
            
            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));
				hbrBkgnd = CreateSolidBrush(RGB(189,219,255));}
        
            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            
            return (INT_PTR)hbrBkgnd;
            
        }break;

		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
			AddMenus(hWnd);
	        AddWinProcAccessDB(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureAccessDB(HINSTANCE hInst){

	WNDCLASSW dialogThird = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255, 235, 170));

    dialogThird.hbrBackground = hb;
    dialogThird.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogThird.hInstance = hInst;
    dialogThird.lpszClassName = L"WindProcAcessDB";
    dialogThird.lpfnWndProc = WindowProcedureAccessDB;

    RegisterClassW(&dialogThird);

}

void displayWindowProcedureAccessDB(HWND hWnd){

    hAccessDBWindow = CreateWindowW(L"WindProcAcessDB", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 300, 350, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccessDB(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                45, 15, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    
    HFONT hFontTXT = CreateFont (16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInside = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));
      
	CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                30, 110, 230, 110, hWnd, NULL, NULL, NULL);
    
    HWND TTL = CreateWindowW(L"Static", L"Which data do you want to access?", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                42, 96, 210, 32, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(TTL, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hDaily = CreateWindowW(L"Button", L"Daily Record", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                80, 135, 150, 25, hWnd, (HMENU)ID_RADIOBTN1, NULL, NULL);
    SendMessage(hDaily, WM_SETFONT, (LPARAM)hFontTXT, TRUE);

    hWeekly = CreateWindowW(L"Button", L"Weekly Record", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                80, 160, 150, 25, hWnd, (HMENU)ID_RADIOBTN2, NULL, NULL);
    SendMessage(hWeekly, WM_SETFONT, (LPARAM)hFontTXT, TRUE);

    hMonthly = CreateWindowW(L"Button", L"Monthly Record", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                80, 185, 150, 25, hWnd, (HMENU)ID_RADIOBTN3, NULL, NULL);
    SendMessage(hMonthly, WM_SETFONT, (LPARAM)hFontTXT, TRUE);


	HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  20, 255, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  160, 255, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);
    
    hwhichAccess = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                42, 500, 150, 32, hWnd, NULL, NULL, NULL);
    SendMessage(TTL, WM_SETFONT, (LPARAM)hFontInside, TRUE);

}


//--------------------------------------------------------------- GCQ WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureGCQ(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;
	

	switch(msg){
		static bool session = false;
        case WM_COMMAND:
        	if (LOWORD(wp) == B0X_1){
        		if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[0] !=1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "1");
                    	num[0]=1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[0] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			if (LOWORD(wp) == B0X_2){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[1] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "2");
                    	num[1] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[1] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			
			if (LOWORD(wp) == B0X_3){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[2] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "3");
                    	num[2] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[2] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//4
			if (LOWORD(wp) == B0X_4){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[3] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "4");
                    	num[3] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[3] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//5
			if (LOWORD(wp) == B0X_5){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[4] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "5");
                    	num[4] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[4] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//6
			if (LOWORD(wp) == B0X_6){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[5] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "6");
                    	num[5] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[5] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//7
			if (LOWORD(wp) == B0X_7){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[6] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "7");
                    	num[6] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[6] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//8
			if (LOWORD(wp) == B0X_8){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[7] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "8");
                    	num[7] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[7] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//9
			if (LOWORD(wp) == B0X_9){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[8] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "9");
                    	num[8] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[8] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//10
			if (LOWORD(wp) == B0X_10){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[9] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "10");
                    	num[9] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[9] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//11
			if (LOWORD(wp) == B0X_11){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[10] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "11");
                    	num[10] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[10] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//12
			if (LOWORD(wp) == B0X_12){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[11] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "12");
                    	num[11] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[11] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//13
			if (LOWORD(wp) == B0X_13){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[12] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "13");
                    	num[12] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[12] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//14
			if (LOWORD(wp) == B0X_14){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[13] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "14");
                    	num[13] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[13] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//15
			if (LOWORD(wp) == B0X_15){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[14] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "15");
                    	num[14] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[14] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//16
			if (LOWORD(wp) == B0X_16){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[15] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "16");
                    	num[15] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[15] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//17
			if (LOWORD(wp) == B0X_17){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[16] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "17");
                    	num[16] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[16] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//18
			if (LOWORD(wp) == B0X_18){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[17] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "18");
                    	num[17] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[17] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//19
			if (LOWORD(wp) == B0X_19){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[18] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "19");
                    	num[18] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[18] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//20
			if (LOWORD(wp) == B0X_20){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[19] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "20");
                    	num[19] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[19] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//21
			if (LOWORD(wp) == B0X_21){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[21];
            		fstream file;
                    ofstream fileOut;
                    file.open("GCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 21; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("GCQ.txt", ios::out);
                    for (int i=0; i < 21; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[20] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "21");
                    	num[20] = 1;
                        for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[20] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
					
            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hThirdWindow, SW_SHOW);
            		ShowWindow(hGCQWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:
					if (session == false){
						MessageBox(hWnd, "Please Select a seat first!", "Selection Error", MB_OK);
						return 0;
					}
					session = false;
					displayWindowProcedurePassInfo(hWnd);
					ShowWindow(hGCQWindow, SW_HIDE);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
				
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcGCQ(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureGCQ(HINSTANCE hInst){

	WNDCLASSW dialogGCQ = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogGCQ.hbrBackground = hb;
    dialogGCQ.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogGCQ.hInstance = hInst;
    dialogGCQ.lpszClassName = L"WindProcGCQ";
    dialogGCQ.lpfnWndProc = WindowProcedureGCQ;

    RegisterClassW(&dialogGCQ);

}

void displayWindowProcedureGCQ(HWND hWnd){

    hGCQWindow = CreateWindowW(L"WindProcGCQ", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  350, 100, 740, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcGCQ(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                260, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"GCQ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 55, 60, 30, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hBus = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                35, 80, 660, 250, hWnd, NULL, NULL, NULL);
    SendMessage(hBus, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGCQBus);

    HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);


    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  590, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

    hGBox1 = CreateWindowW(L"Button", L" 1 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 93, 30, 35, hWnd, (HMENU)B0X_1, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox5 = CreateWindowW(L"Button", L" 5 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 93, 30, 35, hWnd, (HMENU)B0X_5, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox9 = CreateWindowW(L"button", L" 9 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 93, 30, 35, hWnd, (HMENU)B0X_9, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox13 = CreateWindowW(L"button", L" 13 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 93, 30, 35, hWnd, (HMENU)B0X_13, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox17 = CreateWindowW(L"button", L" 17 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 93, 30, 35, hWnd, (HMENU)B0X_17, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox21 = CreateWindowW(L"button", L" 21 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 93, 30, 35, hWnd, (HMENU)B0X_21, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox3 = CreateWindowW(L"button", L" 3 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 140, 30, 35, hWnd, (HMENU)B0X_3, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox7 = CreateWindowW(L"button", L" 7 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 140, 30, 35, hWnd, (HMENU)B0X_7, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    HWND hGBox11 = CreateWindowW(L"button", L" 11 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 140, 30, 35, hWnd, (HMENU)B0X_11, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox15 = CreateWindowW(L"button", L" 15 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 140, 30, 35, hWnd, (HMENU)B0X_15, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox19 = CreateWindowW(L"button", L" 19 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 140, 30, 35, hWnd, (HMENU)B0X_19, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox2 = CreateWindowW(L"button", L" 2 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 280, 30, 35, hWnd, (HMENU)B0X_2, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox6 = CreateWindowW(L"button", L" 6 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 280, 30, 35, hWnd, (HMENU)B0X_6, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox10 = CreateWindowW(L"button", L" 10 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 280, 30, 35, hWnd, (HMENU)B0X_10, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox14 = CreateWindowW(L"button", L" 14 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 280, 30, 35, hWnd, (HMENU)B0X_14, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox18 = CreateWindowW(L"button", L" 18 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 280, 30, 35, hWnd, (HMENU)B0X_18, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox4 = CreateWindowW(L"button", L" 4 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 234, 30, 35, hWnd, (HMENU)B0X_4, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox8 = CreateWindowW(L"button", L" 8 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 234, 30, 35, hWnd, (HMENU)B0X_8, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox12 = CreateWindowW(L"button", L" 12 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 234, 30, 35, hWnd, (HMENU)B0X_12, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox16 = CreateWindowW(L"button", L" 16 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 234, 30, 35, hWnd, (HMENU)B0X_16, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox20 = CreateWindowW(L"button", L" 20 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 234, 30, 35, hWnd, (HMENU)B0X_20, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hSeatNo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 500, 60, 30, hWnd, NULL, NULL, NULL);

}

//--------------------------------------------------------------- MGCQ WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureMGCQ(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){
		static bool session = false;
        case WM_COMMAND:
        	if (LOWORD(wp) == B0X_1){
        		if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[0] !=1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "1");
                    	num[0]=1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[0] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			if (LOWORD(wp) == B0X_2){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[1] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "2");
                    	num[1] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[1] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			
			if (LOWORD(wp) == B0X_3){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[2] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "3");
                    	num[2] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[2] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//4
			if (LOWORD(wp) == B0X_4){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[3] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "4");
                    	num[3] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[3] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//5
			if (LOWORD(wp) == B0X_5){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[4] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "5");
                    	num[4] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[4] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//6
			if (LOWORD(wp) == B0X_6){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[5] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "6");
                    	num[5] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[5] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//7
			if (LOWORD(wp) == B0X_7){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[6] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "7");
                    	num[6] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[6] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//8
			if (LOWORD(wp) == B0X_8){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[7] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "8");
                    	num[7] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[7] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//9
			if (LOWORD(wp) == B0X_9){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[8] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "9");
                    	num[8] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[8] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//10
			if (LOWORD(wp) == B0X_10){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[9] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "10");
                    	num[9] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[9] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//11
			if (LOWORD(wp) == B0X_11){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[10] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "11");
                    	num[10] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[10] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//12
			if (LOWORD(wp) == B0X_12){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[11] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "12");
                    	num[11] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[11] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//13
			if (LOWORD(wp) == B0X_13){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[12] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "13");
                    	num[12] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[12] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//14
			if (LOWORD(wp) == B0X_14){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[13] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "14");
                    	num[13] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[13] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//15
			if (LOWORD(wp) == B0X_15){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[14] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "15");
                    	num[14] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[14] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//16
			if (LOWORD(wp) == B0X_16){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[15] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "16");
                    	num[15] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[15] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//17
			if (LOWORD(wp) == B0X_17){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[16] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "17");
                    	num[16] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[16] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//18
			if (LOWORD(wp) == B0X_18){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[17] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "18");
                    	num[17] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[17] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//19
			if (LOWORD(wp) == B0X_19){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[18] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "19");
                    	num[18] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[18] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//20
			if (LOWORD(wp) == B0X_20){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[19] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "20");
                    	num[19] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[19] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//21
			if (LOWORD(wp) == B0X_23){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[20] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "21");
                    	num[20] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[20] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//22
			if (LOWORD(wp) == B0X_23){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[21] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "22");
                    	num[21] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[21] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//23
			if (LOWORD(wp) == B0X_23){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[23];
            		fstream file;
                    ofstream fileOut;
                    file.open("MGCQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 23; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MGCQ.txt", ios::out);
                    for (int i=0; i < 23; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[22] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "23");
                    	num[22] = 1;
                        for (int i=0; i < 23; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[22] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 21; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hThirdWindow, SW_SHOW);
            		ShowWindow(hMGCQWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:
					if (session == false){
						MessageBox(hWnd, "Please Select a seat first!", "Selection Error", MB_OK);
						return 0;
					}
					session = false;
					displayWindowProcedurePassInfo(hWnd);
					ShowWindow(hMGCQWindow, SW_HIDE);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcMGCQ(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureMGCQ(HINSTANCE hInst){

	WNDCLASSW dialogMGCQ = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogMGCQ.hbrBackground = hb;
    dialogMGCQ.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogMGCQ.hInstance = hInst;
    dialogMGCQ.lpszClassName = L"WindProcMGCQ";
    dialogMGCQ.lpfnWndProc = WindowProcedureMGCQ;

    RegisterClassW(&dialogMGCQ);

}

void displayWindowProcedureMGCQ(HWND hWnd){

    hMGCQWindow = CreateWindowW(L"WindProcMGCQ", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  350, 100, 740, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcMGCQ(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                260, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"MGCQ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                320, 55, 80, 30, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hBus = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                35, 80, 660, 250, hWnd, NULL, NULL, NULL);
    SendMessage(hBus, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGCQBus);

    HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);


    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  590, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

    hGBox1 = CreateWindowW(L"Button", L" 1 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 93, 30, 35, hWnd, (HMENU)B0X_1, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox5 = CreateWindowW(L"Button", L" 5 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 93, 30, 35, hWnd, (HMENU)B0X_5, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox9 = CreateWindowW(L"button", L" 9 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 93, 30, 35, hWnd, (HMENU)B0X_9, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox13 = CreateWindowW(L"button", L" 13 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 93, 30, 35, hWnd, (HMENU)B0X_13, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox17 = CreateWindowW(L"button", L" 17 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 93, 30, 35, hWnd, (HMENU)B0X_17, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox21 = CreateWindowW(L"button", L" 21 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 93, 30, 35, hWnd, (HMENU)B0X_21, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox3 = CreateWindowW(L"button", L" 3 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 140, 30, 35, hWnd, (HMENU)B0X_3, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox7 = CreateWindowW(L"button", L" 7 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 140, 30, 35, hWnd, (HMENU)B0X_7, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    HWND hGBox11 = CreateWindowW(L"button", L" 11 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 140, 30, 35, hWnd, (HMENU)B0X_11, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox15 = CreateWindowW(L"button", L" 15 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 140, 30, 35, hWnd, (HMENU)B0X_15, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox19 = CreateWindowW(L"button", L" 19 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 140, 30, 35, hWnd, (HMENU)B0X_19, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox4 = CreateWindowW(L"button", L" 4 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 280, 30, 35, hWnd, (HMENU)B0X_4, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox8 = CreateWindowW(L"button", L" 8 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 280, 30, 35, hWnd, (HMENU)B0X_8, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox12 = CreateWindowW(L"button", L" 12 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 280, 30, 35, hWnd, (HMENU)B0X_12, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox16 = CreateWindowW(L"button", L" 16 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 280, 30, 35, hWnd, (HMENU)B0X_16, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox20 = CreateWindowW(L"button", L" 20 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 280, 30, 35, hWnd, (HMENU)B0X_20, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox6 = CreateWindowW(L"button", L" 6 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 234, 30, 35, hWnd, (HMENU)B0X_6, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox10 = CreateWindowW(L"button", L" 10 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 234, 30, 35, hWnd, (HMENU)B0X_10, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox14 = CreateWindowW(L"button", L" 14 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 234, 30, 35, hWnd, (HMENU)B0X_14, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox18 = CreateWindowW(L"button", L" 18 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 234, 30, 35, hWnd, (HMENU)B0X_18, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox23 = CreateWindowW(L"button", L" 23 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 280, 30, 35, hWnd, (HMENU)B0X_23, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox2 = CreateWindowW(L"button", L" 2 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 234, 30, 35, hWnd, (HMENU)B0X_2, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox22 = CreateWindowW(L"button", L" 22 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 188, 30, 35, hWnd, (HMENU)B0X_22, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hSeatNo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 500, 60, 30, hWnd, NULL, NULL, NULL);

}


//--------------------------------------------------------------- ECQ WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureECQ(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){
		static bool session = false;
        case WM_COMMAND:
			if (LOWORD(wp) == B0X_1){
        		if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[0] !=1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "1");
                    	num[0]=1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[0] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			if (LOWORD(wp) == B0X_2){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[1] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "2");
                    	num[1] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[1] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			
			if (LOWORD(wp) == B0X_3){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[2] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "3");
                    	num[2] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[2] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//4
			if (LOWORD(wp) == B0X_4){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[3] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "4");
                    	num[3] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[3] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//5
			if (LOWORD(wp) == B0X_5){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[4] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "5");
                    	num[4] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[4] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//6
			if (LOWORD(wp) == B0X_6){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[5] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "6");
                    	num[5] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[5] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//7
			if (LOWORD(wp) == B0X_7){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[6] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "7");
                    	num[6] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[6] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//8
			if (LOWORD(wp) == B0X_8){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[7] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "8");
                    	num[7] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[7] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//9
			if (LOWORD(wp) == B0X_9){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[8] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "9");
                    	num[8] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[8] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//10
			if (LOWORD(wp) == B0X_10){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[9] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "10");
                    	num[9] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[9] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//11
			if (LOWORD(wp) == B0X_11){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[11];
            		fstream file;
                    ofstream fileOut;
                    file.open("ECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 11; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("ECQ.txt", ios::out);
                    for (int i=0; i < 11; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[10] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "11");
                    	num[10] = 1;
                        for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[10] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 11; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
				
            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hThirdWindow, SW_SHOW);
            		ShowWindow(hECQWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:{
					if (session == false){
						MessageBox(hWnd, "Please Select a seat first!", "Selection Error", MB_OK);
						return 0;
					}
					session = false;
					displayWindowProcedurePassInfo(hWnd);
					ShowWindow(hECQWindow, SW_HIDE);
					}break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
             SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));


            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcECQ(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureECQ(HINSTANCE hInst){

	WNDCLASSW dialogECQ = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogECQ.hbrBackground = hb;
    dialogECQ.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogECQ.hInstance = hInst;
    dialogECQ.lpszClassName = L"WindProcECQ";
    dialogECQ.lpfnWndProc = WindowProcedureECQ;

    RegisterClassW(&dialogECQ);

}

void displayWindowProcedureECQ(HWND hWnd){

    hECQWindow = CreateWindowW(L"WindProcECQ", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  350, 100, 740, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcECQ(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                260, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"ECQ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 55, 60, 30, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hBus = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                35, 80, 660, 250, hWnd, NULL, NULL, NULL);
    SendMessage(hBus, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGCQBus);

    HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);


    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  590, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

    hGBox1 = CreateWindowW(L"Button", L" 1 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 93, 30, 35, hWnd, (HMENU)B0X_1, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox3 = CreateWindowW(L"Button", L" 3 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 93, 30, 35, hWnd, (HMENU)B0X_3, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox5 = CreateWindowW(L"button", L" 5 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 93, 30, 35, hWnd, (HMENU)B0X_5, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox7 = CreateWindowW(L"button", L" 7 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 93, 30, 35, hWnd, (HMENU)B0X_7, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox9 = CreateWindowW(L"button", L" 9 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 93, 30, 35, hWnd, (HMENU)B0X_9, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);



    hGBox2 = CreateWindowW(L"button", L" 2 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 280, 30, 35, hWnd, (HMENU)B0X_2, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox4 = CreateWindowW(L"button", L" 4 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 280, 30, 35, hWnd, (HMENU)B0X_4, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox6 = CreateWindowW(L"button", L" 6 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 280, 30, 35, hWnd, (HMENU)B0X_6, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox8 = CreateWindowW(L"button", L" 8 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 280, 30, 35, hWnd, (HMENU)B0X_8, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox10 = CreateWindowW(L"button", L" 10 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 280, 30, 35, hWnd, (HMENU)B0X_10, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);


    hGBox11 = CreateWindowW(L"button", L" 11 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 188, 30, 35, hWnd, (HMENU)B0X_11, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hSeatNo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 500, 60, 30, hWnd, NULL, NULL, NULL);

}

//--------------------------------------------------------------- MECQ WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureMECQ(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){
		static bool session = false;
        case WM_COMMAND:
			if (LOWORD(wp) == B0X_1){
        		if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[0] !=1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "1");
                    	num[0]=1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[0] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			if (LOWORD(wp) == B0X_2){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[1] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "2");
                    	num[1] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[1] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			
			if (LOWORD(wp) == B0X_3){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[2] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "3");
                    	num[2] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[2] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
			}
			//4
			if (LOWORD(wp) == B0X_4){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[3] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "4");
                    	num[3] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[3] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//5
			if (LOWORD(wp) == B0X_5){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[4] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "5");
                    	num[4] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[4] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//6
			if (LOWORD(wp) == B0X_6){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[5] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "6");
                    	num[5] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[5] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//7
			if (LOWORD(wp) == B0X_7){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[6] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "7");
                    	num[6] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[6] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//8
			if (LOWORD(wp) == B0X_8){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[7] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "8");
                    	num[7] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[7] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//9
			if (LOWORD(wp) == B0X_9){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[8] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "9");
                    	num[8] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[8] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//10
			if (LOWORD(wp) == B0X_10){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[9] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "10");
                    	num[9] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[9] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//11
			if (LOWORD(wp) == B0X_11){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[10] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "11");
                    	num[10] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[10] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//12
			if (LOWORD(wp) == B0X_12){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[11] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "12");
                    	num[11] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[11] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//13
			if (LOWORD(wp) == B0X_13){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[12] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "13");
                    	num[12] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[12] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
			//14
			if (LOWORD(wp) == B0X_14){
				if (session == true){
        			MessageBox(hWnd, "You can only select 1 seat.", "Error", MB_OK);
        			return 0;
				}
				int num[14];
            		fstream file;
                    ofstream fileOut;
                    file.open("MECQ.txt", ios::out | ios::in);
                    if (file.is_open())
                        for (int i = 0; i < 14; i++)
                        {
                            file >> num[i];
                        }
                    fileOut.open("MECQ.txt", ios::out);
                    for (int i=0; i < 14; i++)
                    {
                    	if (num[i] == 0){
                    		num[i] = 0;
                    	}
                    }
                    if (num[13] != 1)
                    {
                    	MessageBox(hWnd, "You have taken this seat,\n         Thank you!", "Success", MB_OK);
                    	session = true;
                    	SetWindowText(hSeatNo, "14");
                    	num[13] = 1;
                        for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
                    }
					else if (num[13] == 1){
						MessageBox(hWnd, "This seat is already taken!", "Taken Seat", MB_OK);
						for (int i=0; i < 14; i++)
                        {
                            fileOut << num[i] << endl;
                        }
						return 0;
					}
				}
				
            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hThirdWindow, SW_SHOW);
            		ShowWindow(hMECQWindow, SW_HIDE);
					break;
				case BUTTON_PROCEED:
					if (session == false){
						MessageBox(hWnd, "Please Select a seat first!", "Selection Error", MB_OK);
						return 0;
					}
					session = false;
					displayWindowProcedurePassInfo(hWnd);
					ShowWindow(hMECQWindow, SW_HIDE);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcMECQ(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureMECQ(HINSTANCE hInst){

	WNDCLASSW dialogMECQ = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogMECQ.hbrBackground = hb;
    dialogMECQ.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogMECQ.hInstance = hInst;
    dialogMECQ.lpszClassName = L"WindProcMECQ";
    dialogMECQ.lpfnWndProc = WindowProcedureMECQ;

    RegisterClassW(&dialogMECQ);

}

void displayWindowProcedureMECQ(HWND hWnd){

    hMECQWindow = CreateWindowW(L"WindProcMECQ", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  350, 100, 740, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcMECQ(HWND hWnd){

	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                260, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"MECQ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                320, 55, 80, 30, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hBus = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                35, 80, 660, 250, hWnd, NULL, NULL, NULL);
    SendMessage(hBus, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGCQBus);

    HWND hGoBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  30, 340, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hGoBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);


    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  590, 340, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

    hGBox1 = CreateWindowW(L"Button", L" 1 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 93, 30, 35, hWnd, (HMENU)B0X_1, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox3 = CreateWindowW(L"Button", L" 3 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                236, 93, 30, 35, hWnd, (HMENU)B0X_3, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox5 = CreateWindowW(L"button", L" 5 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                336, 93, 30, 35, hWnd, (HMENU)B0X_5, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

     hGBox7 = CreateWindowW(L"button", L" 7 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                436, 93, 30, 35, hWnd, (HMENU)B0X_7, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox9 = CreateWindowW(L"button", L" 9 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                536, 93, 30, 35, hWnd, (HMENU)B0X_9, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);


    hGBox4 = CreateWindowW(L"button", L" 4 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                186, 280, 30, 35, hWnd, (HMENU)B0X_4, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox6 = CreateWindowW(L"button", L" 6 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                286, 280, 30, 35, hWnd, (HMENU)B0X_6, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox8 = CreateWindowW(L"button", L" 8 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                386, 280, 30, 35, hWnd, (HMENU)B0X_8, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox10 = CreateWindowW(L"button", L" 10 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                486, 280, 30, 35, hWnd, (HMENU)B0X_10, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox11 = CreateWindowW(L"button", L" 11 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                586, 280, 30, 35, hWnd, (HMENU)B0X_11, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);


    hGBox13 = CreateWindowW(L"button", L" 13 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 188, 30, 35, hWnd, (HMENU)B0X_13, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox12 = CreateWindowW(L"button", L" 12 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 280, 30, 35, hWnd, (HMENU)B0X_12, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox2 = CreateWindowW(L"button", L" 2 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                136, 234, 30, 35, hWnd, (HMENU)B0X_2, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hGBox14 = CreateWindowW(L"button", L" 14 ", WS_VISIBLE | WS_CHILD|SS_CENTER|WS_BORDER,
                636, 93, 30, 35, hWnd, (HMENU)B0X_14, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);
    
    hSeatNo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_CENTER,
                340, 500, 60, 30, hWnd, NULL, NULL, NULL);

}

//--------------------------------------------------------------- PASSENGER INFORMATION WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedurePassInfo(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){

        case WM_COMMAND:
            if ( HIWORD(wp) == CBN_SELCHANGE) {
                LRESULT selPick = SendMessage(hPickUp, CB_GETCURSEL, 0, 0);
                LRESULT selDrop = SendMessage(hDropOff, CB_GETCURSEL, 0, 0);
                SetFocus(hWnd);
            }

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
				case BUTTON_PROCEED:
					ofstream openDaily;
					openDaily.open("Daily.txt", std::ios_base::app);
					ofstream openWeekly;
					openWeekly.open("Weekly.txt", std::ios_base::app);
					ofstream openMonthly;
					openWeekly.open("Monthly.txt", std::ios_base::app);
					static char qstatus[100], busno[100], seatno[100], vacstat[100], name[100], add[100], contact[100], 
	        pickup[100], dropoff[100];
	        
	        GetWindowText(hQStore, qstatus, 100);
	        GetWindowText(hBusChoice, busno, 100);
	        GetWindowText(hSeatNo, seatno, 100);
	        GetWindowText(hVaccStatus, vacstat, 100);
	        GetWindowText(hNameEdit, name, 100);
	        GetWindowText(hAddressEdit, add, 100);
	        GetWindowText(hContactEdit, contact, 100);
	        GetWindowText(hPickUp, pickup, 100);
	        GetWindowText(hDropOff, dropoff, 100);

					openDaily << qstatus << "		" << busno << "   " << seatno << "  \t" << vacstat << "   \t" << name << "        \t" << add << "\t\t" << contact << "      \t" << pickup << "      \t" << dropoff << endl;
					openDaily.close();
					
					MessageBox(hWnd, "Information Saved.", "EdsaXpress", MB_OK|MB_ICONEXCLAMATION);
					ShowWindow(hPassInfoWindow, SW_HIDE);
					ShowWindow(hInitialWindow, SW_SHOW);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(164, 199, 241));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));
				hbrBkgnd = CreateSolidBrush(RGB(189,219,255));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcPassInfo(hWnd);
	        static char qstatus[100], busno[100], seatno[100], vacstat[100], name[100], add[100], contact[100], 
	        pickup[100], dropoff[100];
	        
	        GetWindowText(hQStore, qstatus, 100);
	        SetWindowText(hQClassStat, qstatus);
	        
	        GetWindowText(hBusChoice, busno, 100);
	        SetWindowText(hBusNumStat, busno);
	        
	        GetWindowText(hSeatNo, seatno, 100);
	        SetWindowText(hSeatNumStat, seatno);
	        
	        GetWindowText(hVaccStatus, vacstat, 100);
	        SetWindowText(hVaccStatStat, vacstat);
	        
	        GetWindowText(hNameEdit, name, 100);
	        SetWindowText(hNameStat, name);
	        
	        GetWindowText(hAddressEdit, add, 100);
	        SetWindowText(hAddressStat, add);
	        
	        GetWindowText(hContactEdit, contact, 100);
	        SetWindowText(hContactStat, contact);
	        
	        GetWindowText(hPickUp, pickup, 100);
	        SetWindowText(hPickUpStat, pickup);
	        
	        GetWindowText(hDropOff, dropoff, 100);
	        SetWindowText(hDropOffStat, dropoff);
	        
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedurePassInfo(HINSTANCE hInst){

	WNDCLASSW dialogPassInfo = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogPassInfo.hbrBackground = hb;
    dialogPassInfo.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogPassInfo.hInstance = hInst;
    dialogPassInfo.lpszClassName = L"WindProcPassInfo";
    dialogPassInfo.lpfnWndProc = WindowProcedurePassInfo;

    RegisterClassW(&dialogPassInfo);

}

void displayWindowProcedurePassInfo(HWND hWnd){

    hPassInfoWindow = CreateWindowW(L"WindProcPassInfo", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 340, 440, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcPassInfo(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                60, 15, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (18, 0, 0, 0, FW_SEMIBOLD, TRUE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hCheckBG = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                20, 90, 280, 260, hWnd, NULL, NULL, NULL);
    hPassInfo = CreateWindowW(L"Static", L"Passenger Information", WS_VISIBLE | WS_CHILD|SS_CENTER | WS_BORDER,
                65, 85, 200, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    hQClass = CreateWindowW(L"Static", L"Quarantine Classification: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 120, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hQClass, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hQClassStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                205, 120, 75, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hQClassStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hBusNum = CreateWindowW(L"Static", L"Bus Number: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 145, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hBusNum, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hBusNumStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 145, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hBusNumStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hSeatNum = CreateWindowW(L"Static", L"Seat Number: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 170, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hSeatNum, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hSeatNumStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 170, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hSeatNumStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hVaccStat = CreateWindowW(L"Static", L"Vaccination Status: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 195, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hVaccStat, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hVaccStatStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 195, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hVaccStatStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hName = CreateWindowW(L"Static", L"Name: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 220, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hName, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hNameStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 220, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hNameStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hAddress = CreateWindowW(L"Static", L"Address: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 245, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hAddress, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hAddressStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 245, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hAddressStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hContact = CreateWindowW(L"Static", L"Contact Number: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 270, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hContact, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hContactStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 270, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hContactStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hPickUpP = CreateWindowW(L"Static", L"Pick Up Point: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 295, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hPickUpP, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hPickUpStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 295, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hPickUpStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hDropOffP = CreateWindowW(L"Static", L"Drop Off Point: ", WS_VISIBLE | WS_CHILD|SS_LEFT,
                30, 320, 200, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hDropOffP, WM_SETFONT, (LPARAM)hFontEditInfo, TRUE);

    hDropOffStat = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD|SS_LEFT|ES_AUTOHSCROLL,
                170, 320, 120, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hDropOffStat, WM_SETFONT, (LPARAM)hFontInfo, TRUE);


    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  115, 355, 110, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

}

//--------------------------------------------------------------- ACCESS DATA BASE WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureADataBase(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){

        case WM_COMMAND:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hADataBaseWindow, SW_HIDE);
            		ShowWindow(hInitialWindow, SW_SHOW);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcADataBase(hWnd);
	        open_file(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void display_file(char* path){

    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hBody, data);

}

void open_file( HWND hWnd){

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = "Daily.TXT";

    GetOpenFileName(&ofn);
    display_file(ofn.lpstrFile);

}

void registerWindowProcedureADataBase(HINSTANCE hInst){

	WNDCLASSW dialogADataBase = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogADataBase.hbrBackground = hb;
    dialogADataBase.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogADataBase.hInstance = hInst;
    dialogADataBase.lpszClassName = L"WindProcADataBase";
    dialogADataBase.lpfnWndProc = WindowProcedureADataBase;

    RegisterClassW(&dialogADataBase);

}

void displayWindowProcedureADataBase(HWND hWnd){

    hADataBaseWindow = CreateWindowW(L"WindProcADataBase", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  70, 100, 1015, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcADataBase(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                10, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"Daily Record", WS_VISIBLE | WS_CHILD|SS_CENTER,
                450, 20, 200, 30, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    HWND hTopColumn = CreateWindowW(L"Static",
    L"  Classification  ||   Bus No.  ||  Seat No.  ||  Vaccination S.  ||         NAME         ||          ADDRESS          ||   Contact no.  ||  Pick Up Point ||  Drop Off Point ",
    WS_VISIBLE | WS_CHILD|SS_LEFT|WS_BORDER, 10, 80, 990, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hTopColumn, WM_SETFONT, (LPARAM)hFontInfo, TRUE);
	
	hBody = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | WS_BORDER | ES_READONLY, //declaring the editable text box (the user can input or press the button if they want)
                  10, 110, 990, 300, hWnd, NULL, NULL, NULL);

    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  850, 20, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

}
//--------------------------------------------------------------- ACCESS DATA BASE WEEKLY WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureADataBaseW(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){

        case WM_COMMAND:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hADataBaseWWindow, SW_HIDE);
            		ShowWindow(hInitialWindow, SW_SHOW);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcADataBaseW(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureADataBaseW(HINSTANCE hInst){

	WNDCLASSW dialogADataBaseW = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogADataBaseW.hbrBackground = hb;
    dialogADataBaseW.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogADataBaseW.hInstance = hInst;
    dialogADataBaseW.lpszClassName = L"WindProcADataBaseW";
    dialogADataBaseW.lpfnWndProc = WindowProcedureADataBaseW;

    RegisterClassW(&dialogADataBaseW);

}

void display_fileW(char* path){


    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hBody, data);

}


void open_fileW(HWND hWnd){

    OPENFILENAME ofn2;
    ZeroMemory(&ofn2, sizeof(OPENFILENAME));

    ofn2.lStructSize = sizeof(OPENFILENAME);
    ofn2.hwndOwner = hWnd;
    ofn2.lpstrFile = "Daily.TXT";

    GetOpenFileName(&ofn2);
    display_fileW(ofn2.lpstrFile);

}
void displayWindowProcedureADataBaseW(HWND hWnd){

    hADataBaseWWindow = CreateWindowW(L"WindProcADataBaseW", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  50, 100, 1015, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcADataBaseW(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                10, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"Weekly Record", WS_VISIBLE | WS_CHILD|SS_CENTER,
                450, 20, 200, 30, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    HWND hTopColumn = CreateWindowW(L"Static",
    L"  Classification  ||   Bus No.  ||  Seat No.  ||  Vaccination S.  ||         NAME         ||          ADDRESS          ||   Contact no.  ||  Pick Up Point ||  Drop Off Point ",
    WS_VISIBLE | WS_CHILD|SS_LEFT|WS_BORDER, 10, 80, 990, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hTopColumn, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hBody = CreateWindowW(L"edit", L"",
    WS_VISIBLE | WS_CHILD|ES_LEFT|WS_BORDER|ES_READONLY, 10, 110, 990, 300, hWnd, NULL, NULL, NULL);
    SendMessage(hTopColumn, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  850, 20, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);


}

//--------------------------------------------------------------- ACCESS DATA BASE MONTHLY WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureADataBaseM(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){


	int mbVal;
	bool checked = false;

	switch(msg){

        case WM_COMMAND:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"EdsaXpress \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            	case BUTTON_GOBACK:
            		ShowWindow(hADataBaseMWindow, SW_HIDE);
            		ShowWindow(hInitialWindow, SW_SHOW);
					break;
			}break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(240, 243, 246));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(240, 243, 246));
            }
            return (INT_PTR)hbrBkgnd;
		}break;


		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkMode(hdcStatic,TRANSPARENT);
            hbrBkgnd = CreateSolidBrush(RGB(255, 235, 170));

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(212, 64, 10));}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;


	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
	        AddWinProcADataBaseM(hWnd);
	        }break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void registerWindowProcedureADataBaseM(HINSTANCE hInst){

	WNDCLASSW dialogADataBaseM = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(255,235,170));

    dialogADataBaseM.hbrBackground = hb;
    dialogADataBaseM.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogADataBaseM.hInstance = hInst;
    dialogADataBaseM.lpszClassName = L"WindProcADataBaseM";
    dialogADataBaseM.lpfnWndProc = WindowProcedureADataBaseM;

    RegisterClassW(&dialogADataBaseM);

}

void display_fileM(char* path){


    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hBody, data);

}


void open_fileM( HWND hWnd){

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = "Daily.TXT";

    GetOpenFileName(&ofn);
    display_fileM(ofn.lpstrFile);

}

void displayWindowProcedureADataBaseM(HWND hWnd){

    hADataBaseMWindow = CreateWindowW(L"WindProcADataBaseM", L"EdsaXpress", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  50, 100, 1015, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcADataBaseM(HWND hWnd){


	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                10, 5, 150, 130, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    HFONT hFontInside = CreateFont (35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontEditInfo = CreateFont (15, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

	hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));


    hPassInfo = CreateWindowW(L"Static", L"Monthly Record", WS_VISIBLE | WS_CHILD|SS_CENTER,
                400, 20, 250, 40, hWnd, NULL, NULL, NULL);
    SendMessage(hPassInfo, WM_SETFONT, (LPARAM)hFontInside, TRUE);

    HWND hTopColumn = CreateWindowW(L"Static",
    L"  Classification  ||   Bus No.  ||  Seat No.  ||  Vaccination S.  ||         NAME         ||          ADDRESS          ||   Contact no.  ||  Pick Up Point ||  Drop Off Point ",
    WS_VISIBLE | WS_CHILD|SS_LEFT|WS_BORDER, 10, 80, 990, 20, hWnd, NULL, NULL, NULL);
    SendMessage(hTopColumn, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    hBody = CreateWindowW(L"edit", L"",
    WS_VISIBLE | WS_CHILD|ES_LEFT|WS_BORDER|ES_READONLY, 10, 110, 990, 300, hWnd, NULL, NULL, NULL);
    SendMessage(hTopColumn, WM_SETFONT, (LPARAM)hFontInfo, TRUE);

    HWND hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  850, 20, 110, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessageW(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);
}
