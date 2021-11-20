
## Xiro Xplorer Mini

# ��饥 ���ᠭ��

6" ᪫����� ����ப����, �ࠢ����� �� Wifi � ⥫�䮭�. ����� FullHD � �����஭��� �⠡�����樥�.
����ப���� ��⠥� �᪫��⥫쭮 � ०��� 㤥ঠ��� ����� � ����樨.
�� ���� �裡 �ந�室�� ��⮬���᪨� ������ � ��� �����.
�६� ����� 10-15���.

�ந�������� �� 2019.

����஥� �� �᭮�� Quallcom Flight SDK � ZeroTech SDK. �祭� �宦 � Zerotech Dobby.

����ப���� �ࠢ���� �ਫ������� Xiro App. � ᮦ������, ��� �� ࠡ�⠥� �� Android 10+. ��࠭�祭�� ���쭮�� ��⠭������ � 100�, ��᫥ 祣� �஭ 㯨ࠥ��� � "����㠫��� �⥭�".

�������� �ࠢ����� �ਫ������� FlightGo (�롨��� ������ ����ப���� Hesper). ���樠��� �㭪樨 �� ࠡ���� (��⮬���᪨� �����/��ᠤ��, ����� �� ����, ��� ������ ������ �����).
�� ��࠭�祭�� ���쭮�� 㢥��祭� �� 200�.

# ��ࢨ��

�� ��������� ����饭� ssh, ftp, http. http �ᯮ������ �ਫ������� ��� ����祭�� preview ����� � ��.

# ������祭�� �� ssh
���짮��⥫�: linaro
��஫�: linaro 


# ����� ����묨 ����� ⥫�䮭�� � ����ப���஬

�ਫ������ ���뫠�� �ࠢ���騥 ������ �� UDP Port 7078.

��ଠ� ����⮢:
0xA0 [Len:byte] [ID:byte] XX XX ... XX  [Sum:byte]

Len - ������ ����� �����
Sub - �㬬� ��� ���� �����, �஬� ᠬ�� �㬬�

������� ������� ���⢥ত����� �஭�� ���뫪�� �⢥⭮�� ����� �� ���� ⥫�䮭� 7088. 
��ଠ� �����:
0X0A [Len:byte] XX XX ... XX [Sum:byte]

�஭ ���뫠�� �������⮪ �� ���� 7078 ⥫�䮭�.


# FPV ������⮪ � ����ப����

�ਫ������ ���樨��� ��⮪ ����� � ���� 6000 ����ய�� �� ���� 7078 ⥫�䮭� ���뫪�� ����� ����:

0xa0 0x09 0xe1 0x01 0x51 0x28 0xa6 0x1b 0xc5

� ���஬ 0xa6 0x1b - ����� ���� 0x1ba6 = 7078, ��⠫�� ����� �� ������. ��� �����ঠ��� �������⮪� �㦭� ���뫠�� ⠪�� ������ ����� 3 ᥪ㭤�.

�������⮪ ���� � �ଠ� h264(? �� ���⢥ত���).

������� ��⮪� ~240-350��/ᥪ ��� ��⮪� 320x240. ����襭�� ��⮪� �롨ࠥ��� � �ਫ������. ���३� �� ॣ㫨����� �������᪨ (? �� ���⢥ত���).

����⪨ ���ந����� �������⮪ � ������� Videolan �� 㤠����:

test.sdp:
c=IN IP4 192.168.4.2
m=video 7078 RTP/AVP 96 
a=rtpmap:96 H264/90000
a=fmtp:96 packetization-mode=1;profile-level-id=42001E  

videolan.exe -i test.sdp

# ����� ������� �ࠢ�����

����� ������� �ࠢ����� ����� �ଠ�:

0xA0 0x18 0x01 [Ch1_hi:Byte] [Ch1_lo:Byte]  ... [Ch10_hi:Byte] [Ch10_lo:Byte] [Sum:Byte]

���� 4 ������ - �⨪� AERT. �������� 1100...1900.

����� 5: Headless. 0x3e8(1000) - off, 0x5dc(1500) - on.
�ਫ������ FlightGo ���뫠�� 1500, ���⮬� � ��� �஭ ��⠥� � Headless ०���.

����� 6: �।������⥫쭮 RTH(�� ࠡ�⠥�). Xiro app: 0x03e8, Flight Go: 0x00dc 

����� 7: PTZ ������ ⮫쪮 �᫨ � ����� 6 ���뫠���� ���祭�� 0x00dc (? �� ���⢥ত���). �ࠢ�� ����ᨪ� ���� Xiro Mini.

����� 8: ���/����� (�� ࠡ�⠥�). ����� ����ᨪ� ���� Xiro Mini.

����� 9: Takeoff/Landing (�� ࠡ�⠥�).

����� 10: ��࠭�祭�� ����ﭨ�. 0x7D0 - 100m, 0x5dc - 420m. ����⥧�: 0x3e8 - 500m.

# ����

��� �⮣� ����ப���� �뫮 ���饭� ��࠭�祭��� ������⢮ ���⮢ �ࠢ�����, � ������� ������ ����� ����� �� 500� � �⮡ࠦ����� ����� � ⥫����ਨ �� ⥫�䮭�.
��� �ᯮ�짮����� ����, � �ਫ������ Xiro App ����室��� "�ਢ易�� ����ப���� � �����".

���� xiro mini - �� wifi ९��� + ����, ������祭�� � ९���� �� uart. ��ଠ� ����⮢ �� uart ᮢ������ � �ଠ⮬ ����⮢ �� UDP ���� 7088, ����� ���뫠�� �ਫ������.

�஭ ᠬ ���㤠 �� ᮥ�������. �� �ᥣ�� ���� �窮� ����㯠. "�ਢ易�� �஭ � �����" - �� ���⠢��� ���� (���⥭���) ᮥ�������� � �஭�� � "㤫�����" ��� ���. ����䮭 ᮥ������� � ९��஬.

�� ���⥭��� ���� ���� ����� �ࢨ�, ����� �������� �ਫ������ ��।�����, �� �� ��᥮����� � �� ����.

���� Xiro Mini ��ન����� ����஬ 5810. ���� Xiro Xplorer V ��ન����� ����஬ 5800, � Xiro Mini �� ���室��.


# ����祭�� ����� � ����� �।�⢠�� Quallcom Flight SDK

����⢥� ����������� ������� ����ࠦ���� � ����� � ������� �⨫��� qcamvid �� Quallcom flight SDK:

��ᮥ�������� �� ssh, linaro/linaro
sudo qcamvid -c hires -r 720p -s -t 600

� VideoLan ������ url: rtsp://192.168.1.1:554/fpvview

������� ����� � ������ ������:
sudo qcamvid -c optic -r 720p -s -t 600

����� ��権:
qcamvid -h 

����প� �祭� ������.


# ��������� �ࠢ����� ����ப���஬ � ������� ESP32

��� �ࠢ����� �ࠤப���஬ �㦭� ��ᮥ�������� � ��� Wifi �� � ���뫠�� ������ ������� �ࠢ����� �� UDP Port 7088 20 ࠧ � ᥪ㭤�.
�� �⮬ �ਫ������ 㦥 �� ᬮ��� ᮥ�������� � ����ப���஬, ��⮬� �� "�஭ ������祭 � ��㣮�� ���짮��⥫�".

� �����쭮� ॠ����樨 �ࠢ����� ���⮬ �㦭� ���墠�뢠�� ����� �ਫ������ �� ⥫�䮭� � ��������� ������ �ࠢ�����.

� �������饩 ॠ����樨 ESP32 ��ᮥ������� � �஭�(192.168.1.1) ����䥩ᮬ STA, � ���뢠�� ��� ����㯠 ��� ⥫�䮭� �� ����䥩� AP(192.168.4.1).
��᪮�쪮 � ESP32 ��� ��⨭�� ����⮢ ����� ����䥩ᠬ�, ������ �� �ਫ������ �� ��室�� �� �஭� � �� ����� ESP32 �ࠢ���� ����ப���஬.
�ਫ������ ����� �� ������������� � �஭��. 
�⮡� ���-� ॠ�������� ������ �����, ESP32 ����뫠�� �� ������ ⥫����ਨ (���� 7088) � �����(���� 7078) �� ⥫�䮭 (192.168.4.2).
�ਫ������ �㤥� ���ਭ����� �� ������, ⮫쪮 �᫨ 㦥 �뫮 ᮥ����� � �஭��. �� ���� ᭠砫� �㦭� ��ᮥ�������� � �஭� �������,
��⠭����� ���, � ��⥬ 㦥 ������� ���� � ��४����� ⥫���� �� ��� ����. (Update: ����� � �ਫ������ �⮡ࠦ�����, ⥫������ ���).
�஢�७�� ⮫쪮 � Xiro App.

��� ���樨஢���� ��।�� �������⮪� �� esp32 �㦭� ���뫠�� ������ 0xa0 0x09 0xe1 ... ����� �� ᥪ㭤�.
ESP �ࠢ����� ⮫쪮 � ��⮪�� 320x240.

��� �ࠢ��쭮� ॠ����樨(� �������� ����⮢ �� �ਫ������) �㦭� ࠧ�������, ��� ᤥ��� �஥�� ESP32 NAT Router https://github.com/martin-ger/esp32_nat_router
�ਤ���� ࠧ������� � ������⥪�� lwip.

����� ���� ᫥����� ����, �������� ��� ॠ����㥬��:
����䮭 ������砥��� � AP 192.168.4.1 Gateway 192.168.4.1 � ����砥� ���� 192.168.4.2. �ਫ������ ���뫠�� ������ �஭� �� ���� 192.168.1.1, ����� ���� �� default gateway 192.6.4.1(ESP32 AP interface).
�� �� ������ ���������� �ਭ��� �� ESP32(192.168.4.1) �� �஢�� ᮪�⮢. ������, ����� ���� ����� ������� sniffer callback � ࠧ����� ���蠭�� �����.

# � ��⨭�� � ESP32:

ESP32 IP forwarding, bridging, routing
https://esp32.com/viewtopic.php?t=9



���ଠ�� ᮡ࠭� 童���� ᮮ���⢠ XIRO Drone | DIY � Telegram