
undefined4 Curl_init_userdefined(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = stdout;
  uVar1 = stdin;
  *param_1 = stderr;
  param_1[4] = uVar2;
  param_1[5] = uVar1;
  param_1[0x16] = fwrite;
  param_1[0x19] = fread;
  param_1[0x56] = 5;
  param_1[3] = 0x438;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x10] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  *(undefined *)((int)param_1 + 0x1c6) = 0;
  param_1[0x5d] = 0;
  param_1[0x32] = 0xffffffff;
  param_1[0x33] = 0xffffffff;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0x4a] = 1;
  param_1[0xaf] = 1;
  *(undefined *)(param_1 + 0x71) = 1;
  *(undefined *)((int)param_1 + 0x1c5) = 1;
  param_1[0x66] = 1;
  param_1[9] = 1;
  param_1[10] = 1;
  *(undefined *)((int)param_1 + 0x1af) = 1;
  *(undefined *)(param_1 + 0x4e) = 1;
  *(undefined *)((int)param_1 + 0x139) = 1;
  param_1[0x5e] = 0x3c;
  param_1[0x5c] = 0;
  param_1[0x77] = 0xffffffff;
  *(undefined *)(param_1 + 0x59) = 1;
  param_1[0xab] = 0xffffffff;
  *(undefined *)(param_1 + 0xb1) = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  *(undefined *)(param_1 + 0xb7) = 0;
  param_1[0xb9] = 0x3c;
  param_1[0xb8] = 0x3c;
  *(undefined *)(param_1 + 0xbb) = 1;
  *(undefined *)((int)param_1 + 0x2ed) = 1;
  *(undefined *)(param_1 + 0x3f) = 1;
  param_1[0x79] = 0x1a4;
  param_1[0x7a] = 0x1ed;
  param_1[0xac] = 0xf3fffbef;
  param_1[0xbc] = 1000;
  return 0;
}

