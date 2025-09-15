
void Curl_ossl_seed(int param_1)

{
  char *file;
  int iVar1;
  uchar auStack_50 [64];
  
  if (((ssl_seeded_25109 != '\0') && (*(int *)(param_1 + 0x3a4) == 0)) &&
     (*(int *)(param_1 + 0x3a0) == 0)) {
    return;
  }
  if (*(int *)(param_1 + 0x29c) != 0) {
    file = *(char **)(param_1 + 0x3a4);
    if (file == (char *)0x0) {
      file = "";
    }
    RAND_load_file(file,0x400);
    iVar1 = RAND_status();
    if (iVar1 != 0) {
      ssl_seeded_25109 = 1;
      return;
    }
  }
  if (((*(char **)(param_1 + 0x3a0) == (char *)0x0) ||
      (iVar1 = RAND_egd(*(char **)(param_1 + 0x3a0)), iVar1 == -1)) ||
     (iVar1 = RAND_status(), iVar1 == 0)) {
    do {
      RAND_bytes(auStack_50,0x40);
      RAND_add(auStack_50,0x40,32.0);
      iVar1 = RAND_status();
    } while (iVar1 == 0);
    *(undefined1 *)(param_1 + 0x59c) = 0;
    RAND_file_name((char *)(param_1 + 0x59c),0x4000);
    if (*(char *)(param_1 + 0x59c) != '\0') {
      RAND_load_file((char *)(param_1 + 0x59c),0x400);
      iVar1 = RAND_status();
      if (iVar1 != 0) {
        ssl_seeded_25109 = 1;
        return;
      }
    }
    Curl_infof(param_1,"libcurl is now using a weak random seed!\n");
  }
  ssl_seeded_25109 = 1;
  return;
}

