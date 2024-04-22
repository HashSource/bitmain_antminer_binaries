
int inflate_stream(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar4 = param_2 + 0x94;
  uVar6 = *(undefined4 *)(param_2 + 0x98);
  uVar7 = *(undefined4 *)(param_2 + 0x94);
  iVar1 = (**DAT_0004cee4)(0x4000);
  if (iVar1 == 0) {
    inflateEnd(iVar4);
    *(undefined4 *)(param_2 + 0x90) = 0;
    return 0x1b;
  }
  bVar5 = 1;
  do {
    *(int *)(param_2 + 0xa0) = iVar1;
    *(undefined4 *)(param_2 + 0xa4) = 0x4000;
    uVar2 = inflate(iVar4,2);
    if (uVar2 < 2) {
      if (((*(int *)(param_2 + 0xa4) != 0x4000) && (*(char *)(param_2 + 0xe5) == '\0')) &&
         (iVar3 = Curl_client_write(param_1,1,iVar1,0x4000 - *(int *)(param_2 + 0xa4)), iVar3 != 0))
      {
        (**DAT_0004ceec)(iVar1);
        inflateEnd(iVar4);
        *(undefined4 *)(param_2 + 0x90) = 0;
        return iVar3;
      }
      if (uVar2 == 1) {
        (**DAT_0004ceec)(iVar1);
        iVar1 = inflateEnd(iVar4);
        if (iVar1 == 0) {
          inflateEnd(iVar4);
          *(undefined4 *)(param_2 + 0x90) = 0;
          return 0;
        }
LAB_0004ce38:
        iVar1 = process_zlib_error(param_1,iVar4);
        inflateEnd(iVar4);
        *(undefined4 *)(param_2 + 0x90) = 0;
        return iVar1;
      }
      if (*(int *)(param_2 + 0x98) == 0) {
        (**DAT_0004ceec)(iVar1);
        return 0;
      }
    }
    else {
      if (!(bool)(uVar2 == 0xfffffffd & bVar5)) {
        (**DAT_0004ceec)(iVar1);
        iVar1 = process_zlib_error(param_1,iVar4);
        inflateEnd(iVar4);
        *(undefined4 *)(param_2 + 0x90) = 0;
        return iVar1;
      }
      inflateEnd(iVar4);
      iVar3 = inflateInit2_(iVar4,0xfffffff1,DAT_0004cee8,0x38);
      if (iVar3 != 0) {
        (**DAT_0004ceec)(iVar1);
        goto LAB_0004ce38;
      }
      *(undefined4 *)(param_2 + 0x94) = uVar7;
      *(undefined4 *)(param_2 + 0x98) = uVar6;
    }
    bVar5 = 0;
  } while( true );
}

