
int curl_easy_escape(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_3 + 1;
  if (param_3 == 0) {
    sVar2 = strlen(param_2);
    uVar8 = sVar2 + 1;
  }
  iVar3 = (**DAT_00048380)(uVar8);
  if (iVar3 != 0) {
    if (uVar8 == 1) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      pcVar5 = param_2 + -1;
      uVar7 = uVar8;
      uVar9 = uVar8;
      do {
        cVar1 = pcVar5[1];
        switch(cVar1) {
        case '-':
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '_':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case '~':
          *(char *)(iVar3 + iVar6) = cVar1;
          iVar6 = iVar6 + 1;
          break;
        default:
          uVar9 = uVar9 + 2;
          iVar4 = iVar3;
          if (uVar7 < uVar9) {
            uVar7 = uVar7 << 1;
            iVar4 = (*Curl_crealloc)(iVar3,uVar7);
            if (iVar4 == 0) {
              (**DAT_00048388)(iVar3);
              return 0;
            }
          }
          iVar3 = iVar4 + iVar6;
          iVar6 = iVar6 + 3;
          curl_msnprintf(iVar3,4,DAT_00048384,cVar1);
          iVar3 = iVar4;
        }
        iVar4 = -3 - (int)pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (param_2 + uVar8 + iVar4 != (char *)0x0);
    }
    *(undefined *)(iVar3 + iVar6) = 0;
  }
  return iVar3;
}

