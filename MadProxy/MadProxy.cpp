/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
// MadProxy.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

byte byte_403018[11] = {0x79,0x0B0,0x75,0x0BE,0x4D,0x0BD,0x4D,0x99,0x66,0x9A,0x21};

signed int sub_401000(int a1, char a2, int a3)
{
  int v3; // esi@3
  char v4; // dl@4
  signed int result; // eax@5

  if ( a3 && a1 )
  {
    v3 = (a2 & 0x3F) << 8;
    do
    {
      v4 = *(&byte_403018[*(BYTE *)(a3 + a1-- - 1)] + v3);
      *(BYTE *)(a3 + a1) = v4;
    }
    while ( a1 );
    result = 0;
  }
  else
  {
    result = -1;
  }
  return result;
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
  SOCKET v4; // esi@11
  SOCKET v5; // ebx@17
  SOCKET v6; // esi@17
  signed int v7; // ebx@23
  int i; // ebx@25
  HANDLE v9; // eax@27
  HANDLE v10; // eax@28
  HANDLE v11; // eax@35
  char v12; // zf@35
  char v13; // zf@38
  int j; // ebx@41
  HANDLE v15; // eax@43
  HANDLE v16; // eax@44
  HANDLE v17; // eax@51
  char v18; // zf@51
  char v19; // zf@56
  const char *v20; // [sp-4h] [bp-102FCh]@8
  WORD v21; // [sp-4h] [bp-102FCh]@30
  WORD v22; // [sp-4h] [bp-102FCh]@46
  char v23; // [sp+Ch] [bp-102ECh]@1
  int v24; // [sp+10h] [bp-102E8h]@21
  int v25; // [sp+14h] [bp-102E4h]@21
  int v26; // [sp+18h] [bp-102E0h]@21
  SOCKET s; // [sp+1Ch] [bp-102DCh]@17
  SOCKET v28; // [sp+20h] [bp-102D8h]@17
  int v29; // [sp+24h] [bp-102D4h]@21
  int v30; // [sp+28h] [bp-102D0h]@22
  u_short hostshort[2]; // [sp+2Ch] [bp-102CCh]@5
  u_long argp; // [sp+30h] [bp-102C8h]@21
  int v33; // [sp+34h] [bp-102C4h]@21
  sockaddr_in v34; // [sp+38h] [bp-102C0h]@19
  u_short v35; // [sp+3Ah] [bp-102BEh]@19
  unsigned __int32 v36; // [sp+3Ch] [bp-102BCh]@19
  struct sockaddr name; // [sp+48h] [bp-102B0h]@13
  struct WSAData WSAData; // [sp+58h] [bp-102A0h]@7
  char buf[2]; // [sp+1E8h] [bp-10110h]@23
  char v40[5]; // [sp+1EAh] [bp-1010Eh]@23
  unsigned __int8 v41; // [sp+1EFh] [bp-10109h]@55
  char cp; // [sp+101F0h] [bp-108h]@2
  unsigned int v43; // [sp+102F4h] [bp-4h]@1

 // v43 = (unsigned int)&v23 ^ ___security_cookie;
  printf("BakaBug's Kal Proxy");
  if ( argc <= 1 )
  {
    printf("\n\n Server: ");
    scanf("%s%*c", &cp);
  }
  else
  {
    sprintf(&cp, "%s", argv[1]);
    printf("\n\n Server: %s", &cp);
  }
  if ( argc <= 2 )
  {
    printf(" Port  : ");
    scanf("%d%*c", hostshort);
  }
  else
  {
    *(DWORD *)hostshort = atoi(argv[2]);
    printf(" Port  : %d", *(DWORD *)hostshort);
  }
  printf(" \nStarting proxy Server...");
  if ( WSAStartup(0x202u, &WSAData) )
  {
    v20 = "Error in WSA Startup";
LABEL_9:
    printf(v20);
    goto LABEL_10;
  }
  v4 = socket(2, 1, 6);
  if ( v4 == -1 )
  {
    WSACleanup();
    v20 = "Error at create socket";
    goto LABEL_9;
  }
  name.sa_family = 2;
  *(DWORD *)&name.sa_data[2] = 0;
  *(WORD *)&name.sa_data[0] = htons(0x7531u);
  if ( bind(v4, &name, 16) == -1 )
  {
    closesocket(v4);
    v20 = "Error in BIND";
    goto LABEL_9;
  }
  if ( listen(v4, 5) == -1 )
  {
    v20 = "Error in LISTEN";
    goto LABEL_9;
  }
  printf("\nPlease connect now..");
  v6 = accept(v4, 0, 0);
  s = v6;
  printf("\nConnecting to the KalServer..");
  v5 = socket(2, 1, 6);
  v28 = v5;
  if ( v5 == -1 )
  {
    WSACleanup();
    printf("Error at create socket");
  }
  else
  {
	//sockaddr_in clientService;
   // clientService.sin_family = AF_INET;
  //  clientService.sin_addr.s_addr = inet_addr("127.0.0.1");//inet_addr(&cp);
 //   clientService.sin_port =   htons(30002);//htons(hostshort[0]);
    v34.sin_family = 2;
    v34.sin_addr.s_addr  = inet_addr(&cp);
    v34.sin_port = htons(hostshort[0]);
    if ( connect(v5, (const struct sockaddr *)&v34, 16) != -1 )
    {
      printf("\nConnected !!\n\n\n");
      argp = 1;
      ioctlsocket(v6, -2147195266, &argp);
      ioctlsocket(v5, -2147195266, &argp);
      v25 = 0;
      v26 = 0;
      v24 = 0;
      v33 = 0;
      v29 = 0;
      while ( 1 )
      {
		Sleep(1);
		  //printf("DebugPoint 1");
        ioctlsocket(s, 1074030207, (u_long *)&v30);
        if ( v30 )
        {
          recv(s, buf, 2, 0);
          recv(s, v40, *(unsigned __int16 *)buf - 2, 0);
          send(v5, buf, *(unsigned __int16 *)buf, 0);
          v7 = v29;
         // sub_401000(*(unsigned __int16 *)buf - 2, v29, (int)v40);
          v29 = v7 + 1;
		//   printf("DebugPoint 2");
          if ( v7 >= 64 )
            v29 = 0;
          for ( i = 0; i < *(unsigned __int16 *)buf - 2; ++i )
          {
            if ( !v25 )
            {
              v9 = GetStdHandle(0xFFFFFFF5u);
              SetConsoleTextAttribute(v9, 0xFu);
              printf("0x%0.4x: ", v26++); //White Counter 
            }
            v10 = GetStdHandle(0xFFFFFFF5u);
            SetConsoleTextAttribute(v10, 0xFu);
            if ( v24 )
            {
              if ( i )
                v21 = 114;
              else
                v21 = 116;
            }
            else
            {
              if ( i )
                v21 = 130;
              else
                v21 = 132;
            }
            v11 = GetStdHandle(0xFFFFFFF5u);
            SetConsoleTextAttribute(v11, v21);
            printf("%0.2x ", (unsigned __int8)v40[i]); // RED
            v12 = v25++ == 23;
            if ( v12 )
              v25 = 0;
          }
          v5 = v28;
          v13 = v24++ == 1;
		    //printf("DebugPoint 3");
          if ( v13 )
            v24 = 0;
        }
		  //printf("DebugPoint 4");
		// FEEEEEEEEEEEEEEEEEEEEEEEEEEEEEHLLLLLLLERRRRRRRRRRRRRRRRRRRRRRRR
        ioctlsocket(v5, 1074030207, (u_long *)&v30);
        if ( v30 )
        {
			printf("DebugPointASD");
          recv(v5, buf, 2, 0);
          recv(v5, v40, *(unsigned __int16 *)buf - 2, 0);
          send(s, buf, *(unsigned __int16 *)buf, 0);
      //    sub_401000(*(unsigned __int16 *)buf - 2, v33, (int)v40);
          for ( j = 0; j < *(unsigned __int16 *)buf - 2; ++j )
          {
            if ( !v25 )
            {
              v15 = GetStdHandle(0xFFFFFFF5u);
              SetConsoleTextAttribute(v15, 0xFu);
              printf("0x%0.4x: ", v26++); //COunter
			   printf("ASDF");
            }
            v16 = GetStdHandle(0xFFFFFFF5u);
            SetConsoleTextAttribute(v16, 0xFu);
			  //printf("DebugPoint 5");
            if ( v24 )
            {
              if ( j )
                v22 = 113;
              else
                v22 = 116;
            }
            else
            {
              if ( j )
                v22 = 129;
              else
                v22 = 132;
            }
            v17 = GetStdHandle(0xFFFFFFF5u);
            SetConsoleTextAttribute(v17, v22);
			  //printf("DebugPoint 6");
            printf("%0.2x ", (unsigned __int8)v40[j]); //BLUE
			 printf("QQQQQQ");
            v18 = v25++ == 23;
            if ( v18 )
              v25 = 0;
          }
          if ( v40[0] == 42 )
          {
            v33 = v41;
            v29 = v41;
          }
          v5 = v28;
          v19 = v24++ == 1;
          if ( v19 )
            v24 = 0;
        }
      }
    }
    printf("Failed to connect.\n");
    WSACleanup();
  }
LABEL_10:
  getchar();
  return 0;
}