
undefined1 * ssl_conf_cmd_lookup(uint *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  if (param_2 == (char *)0x0) {
    return (undefined1 *)0x0;
  }
  uVar5 = *param_1;
  uVar1 = uVar5 & 8;
  uVar4 = uVar5 & 0x20;
  uVar7 = uVar5 & 1;
  uVar3 = uVar5 & 2;
  if ((int)(uVar5 << 0x1d) < 0) {
    if (uVar3 == 0) {
      if (uVar1 == 0) {
        if (uVar4 == 0) {
          puVar6 = &ssl_conf_cmds;
          do {
            HintPreloadData(puVar6 + 0x7c);
            if (((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) &&
                (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a))) &&
               ((uVar7 != 0 &&
                ((*(char **)(puVar6 + 8) != (char *)0x0 &&
                 (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))))) {
              return puVar6;
            }
            puVar6 = puVar6 + 0x10;
          } while (puVar6 != ssl_vfy_list_25895);
        }
        else {
          puVar6 = &ssl_conf_cmds;
          do {
            HintPreloadData(puVar6 + 0x8c);
            if ((((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) && (uVar7 != 0)) &&
                (*(char **)(puVar6 + 8) != (char *)0x0)) &&
               (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
              return puVar6;
            }
            puVar6 = puVar6 + 0x10;
          } while (puVar6 != ssl_vfy_list_25895);
        }
      }
      else if (uVar4 == 0) {
        puVar6 = &ssl_conf_cmds;
        do {
          HintPreloadData(puVar6 + 0x8c);
          if (((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a)) && (uVar7 != 0)) &&
             ((*(char **)(puVar6 + 8) != (char *)0x0 &&
              (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
            return puVar6;
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
      else {
        puVar6 = &ssl_conf_cmds;
        do {
          if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
             (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
            return puVar6;
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
    }
    else if (uVar4 == 0) {
      if (uVar1 == 0) {
        puVar6 = &ssl_conf_cmds;
        do {
          HintPreloadData(puVar6 + 0x5c);
          if ((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) &&
             (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a))) {
            if ((uVar7 != 0) &&
               ((*(char **)(puVar6 + 8) != (char *)0x0 &&
                (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
              return puVar6;
            }
            if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
               (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
              return puVar6;
            }
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
      else {
        puVar6 = &ssl_conf_cmds;
        do {
          HintPreloadData(puVar6 + 0x5c);
          if (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a)) {
            if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
               (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
              return puVar6;
            }
            if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
               (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
              return puVar6;
            }
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
    }
    else if (uVar1 == 0) {
      puVar6 = &ssl_conf_cmds;
      do {
        HintPreloadData(puVar6 + 0x5c);
        if (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) {
          if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
             (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
            return puVar6;
          }
          if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
             (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
            return puVar6;
          }
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
    else {
      puVar6 = &ssl_conf_cmds;
      do {
        if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
           (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
          return puVar6;
        }
        HintPreloadData(puVar6 + 0x54);
        if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
           (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
          return puVar6;
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
  }
  else if (uVar1 == 0) {
    if (uVar3 == 0) {
      if (uVar4 == 0) {
        puVar6 = &ssl_conf_cmds;
        do {
          uVar1 = (uint)*(ushort *)(puVar6 + 0xc);
          HintPreloadData(puVar6 + 0x6c);
          if ((((-1 < (int)(uVar1 << 0x1c)) && (-1 < (int)(uVar1 << 0x1d))) &&
              (-1 < (int)(uVar1 << 0x1a))) &&
             (((uVar7 != 0 && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
              (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
            return puVar6;
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
      else {
        puVar6 = &ssl_conf_cmds;
        do {
          HintPreloadData(puVar6 + 0x7c);
          if (((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) &&
              (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d))) &&
             ((uVar7 != 0 &&
              ((*(char **)(puVar6 + 8) != (char *)0x0 &&
               (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))))) {
            return puVar6;
          }
          puVar6 = puVar6 + 0x10;
        } while (puVar6 != ssl_vfy_list_25895);
      }
    }
    else if (uVar4 == 0) {
      puVar6 = &ssl_conf_cmds;
      do {
        uVar1 = (uint)*(ushort *)(puVar6 + 0xc);
        HintPreloadData(puVar6 + 0x4c);
        if (((-1 < (int)(uVar1 << 0x1c)) && (-1 < (int)(uVar1 << 0x1d))) &&
           (-1 < (int)(uVar1 << 0x1a))) {
          if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
             (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
            return puVar6;
          }
          if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
             (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
            return puVar6;
          }
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
    else {
      puVar6 = &ssl_conf_cmds;
      do {
        HintPreloadData(puVar6 + 0x5c);
        if ((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1c)) &&
           (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d))) {
          if ((uVar7 != 0) &&
             ((*(char **)(puVar6 + 8) != (char *)0x0 &&
              (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
            return puVar6;
          }
          if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
             (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
            return puVar6;
          }
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
  }
  else if (uVar3 == 0) {
    if (uVar4 == 0) {
      puVar6 = &ssl_conf_cmds;
      do {
        HintPreloadData(puVar6 + 0x7c);
        if ((((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d)) &&
             (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a))) && (uVar7 != 0)) &&
           ((*(char **)(puVar6 + 8) != (char *)0x0 &&
            (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
          return puVar6;
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
    else {
      puVar6 = &ssl_conf_cmds;
      do {
        HintPreloadData(puVar6 + 0x8c);
        if (((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d)) && (uVar7 != 0)) &&
           ((*(char **)(puVar6 + 8) != (char *)0x0 &&
            (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
          return puVar6;
        }
        puVar6 = puVar6 + 0x10;
      } while (puVar6 != ssl_vfy_list_25895);
    }
  }
  else if (uVar4 == 0) {
    puVar6 = &ssl_conf_cmds;
    do {
      HintPreloadData(puVar6 + 0x5c);
      if ((-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d)) &&
         (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1a))) {
        if ((uVar7 != 0) &&
           ((*(char **)(puVar6 + 8) != (char *)0x0 &&
            (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)))) {
          return puVar6;
        }
        if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
           (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
          return puVar6;
        }
      }
      puVar6 = puVar6 + 0x10;
    } while (puVar6 != ssl_vfy_list_25895);
  }
  else {
    puVar6 = &ssl_conf_cmds;
    do {
      HintPreloadData(puVar6 + 0x5c);
      if (-1 < (int)((uint)*(ushort *)(puVar6 + 0xc) << 0x1d)) {
        if (((uVar7 != 0) && (*(char **)(puVar6 + 8) != (char *)0x0)) &&
           (iVar2 = strcmp(*(char **)(puVar6 + 8),param_2), iVar2 == 0)) {
          return puVar6;
        }
        if ((*(char **)(puVar6 + 4) != (char *)0x0) &&
           (iVar2 = strcasecmp(*(char **)(puVar6 + 4),param_2), iVar2 == 0)) {
          return puVar6;
        }
      }
      puVar6 = puVar6 + 0x10;
    } while (puVar6 != ssl_vfy_list_25895);
  }
  return (undefined1 *)0x0;
}

