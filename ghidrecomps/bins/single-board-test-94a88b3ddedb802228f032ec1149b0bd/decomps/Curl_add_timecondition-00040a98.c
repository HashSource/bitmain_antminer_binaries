
int Curl_add_timecondition(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  iVar1 = *(int *)(param_1 + 0x270);
  if (iVar1 != 0) {
    iVar1 = Curl_gmtime(*(undefined4 *)(param_1 + 0x274),&local_4c);
    if (iVar1 == 0) {
      if (local_34 == 0) {
        local_34 = 6;
      }
      else {
        local_34 = local_34 + -1;
      }
      iVar3 = param_1 + 0x59c;
      curl_msnprintf(iVar3,0x3fff,DAT_00040b50,*(undefined4 *)(DAT_00040b4c + local_34 * 4),local_40
                     ,*(undefined4 *)(DAT_00040b48 + local_3c * 4),local_38 + 0x76c,local_44,
                     local_48,local_4c);
      iVar2 = *(int *)(param_1 + 0x270);
      if (iVar2 == 2) {
        iVar1 = Curl_add_bufferf(param_2,DAT_00040b60,iVar3);
      }
      else if (iVar2 == 3) {
        iVar1 = Curl_add_bufferf(param_2,DAT_00040b5c,iVar3);
      }
      else if (iVar2 == 1) {
        iVar1 = Curl_add_bufferf(param_2,DAT_00040b54,iVar3);
      }
    }
    else {
      Curl_failf(param_1,DAT_00040b58);
    }
  }
  return iVar1;
}

