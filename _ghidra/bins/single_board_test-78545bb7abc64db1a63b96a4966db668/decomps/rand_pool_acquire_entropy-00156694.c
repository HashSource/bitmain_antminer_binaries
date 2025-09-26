
/* WARNING: Removing unreachable block (ram,0x00156702) */
/* WARNING: Removing unreachable block (ram,0x001566f6) */
/* WARNING: Removing unreachable block (ram,0x00156724) */
/* WARNING: Removing unreachable block (ram,0x001568b2) */
/* WARNING: Removing unreachable block (ram,0x001568be) */
/* WARNING: Removing unreachable block (ram,0x00156728) */

void rand_pool_acquire_entropy(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  size_t __nbytes;
  int iVar7;
  void *__buf;
  ssize_t sVar8;
  size_t sVar9;
  uint uVar10;
  stat local_80;
  
  iVar2 = rand_pool_bytes_needed(param_1,1);
  if (iVar2 != 0) {
    iVar7 = 2;
LAB_001566b4:
    do {
      uVar3 = rand_pool_add_begin(param_1,iVar2);
      iVar4 = getentropy(uVar3,iVar2);
      if (iVar4 == 0) {
        lVar6 = iVar2;
        if (0 < iVar2) {
LAB_00156748:
          rand_pool_add_end(param_1,lVar6,lVar6 << 3);
          iVar2 = iVar2 - lVar6;
          if (iVar2 == 0) break;
          iVar7 = 2;
          goto LAB_001566b4;
        }
        piVar5 = __errno_location();
        iVar4 = *piVar5;
LAB_00156760:
        if (iVar4 != 4) break;
      }
      else {
        piVar5 = __errno_location();
        iVar4 = *piVar5;
        if (iVar4 != 0x26) goto LAB_00156760;
        lVar6 = syscall(0x180,uVar3,iVar2,0);
        if (0 < lVar6) goto LAB_00156748;
        if (lVar6 != 0) {
          iVar4 = *piVar5;
          goto LAB_00156760;
        }
      }
      bVar1 = 0 < iVar7;
      iVar7 = iVar7 + -1;
    } while (bVar1);
  }
  iVar2 = rand_pool_entropy_available(param_1);
  if (iVar2 != 0) {
    return;
  }
  iVar2 = wait_random_seeded();
  if (iVar2 != 0) {
    __nbytes = rand_pool_bytes_needed(param_1,1);
    if (__nbytes != 0) {
      iVar2 = 0x21b89b4;
      uVar10 = 0;
      do {
        if ((((*(int *)(iVar2 + -0x34) == -1) ||
             (iVar7 = __fxstat(3,*(int *)(iVar2 + -0x34),&local_80), iVar7 == -1)) ||
            (*(int *)(iVar2 + -0x28) != local_80.st_dev._4_4_ ||
             *(int *)(iVar2 + -0x2c) != (int)local_80.st_dev)) ||
           (((*(__ino_t *)(iVar2 + -0x24) != local_80.st_ino ||
             (HintPreloadData(iVar2),
             ((local_80.st_mode ^ *(uint *)(iVar2 + -0x20)) & 0xfffffe00) != 0)) ||
            (*(int *)(iVar2 + -0x18) != local_80.st_rdev._4_4_ ||
             *(int *)(iVar2 + -0x1c) != (int)local_80.st_rdev)))) {
          iVar7 = open(*(char **)(&random_device_paths + uVar10 * 4),0);
          *(int *)(iVar2 + -0x34) = iVar7;
          if (iVar7 != -1) {
            iVar7 = __fxstat(3,iVar7,&local_80);
            if (iVar7 != -1) {
              iVar7 = *(int *)(iVar2 + -0x34);
              *(int *)(iVar2 + -0x2c) = (int)local_80.st_dev;
              *(int *)(iVar2 + -0x28) = local_80.st_dev._4_4_;
              *(__ino_t *)(iVar2 + -0x24) = local_80.st_ino;
              *(__mode_t *)(iVar2 + -0x20) = local_80.st_mode;
              *(int *)(iVar2 + -0x1c) = (int)local_80.st_rdev;
              *(int *)(iVar2 + -0x18) = local_80.st_rdev._4_4_;
              goto LAB_0015680e;
            }
            close(*(int *)(iVar2 + -0x34));
            *(undefined4 *)(iVar2 + -0x34) = 0xffffffff;
          }
        }
        else {
          iVar7 = *(int *)(iVar2 + -0x34);
LAB_0015680e:
          if (iVar7 != -1) {
            iVar4 = 2;
            do {
              while( true ) {
                __buf = (void *)rand_pool_add_begin(param_1,__nbytes);
                sVar8 = read(iVar7,__buf,__nbytes);
                if (sVar8 < 1) break;
                rand_pool_add_end(param_1,sVar8,sVar8 * 8);
                __nbytes = __nbytes - sVar8;
                iVar4 = 2;
                if (__nbytes == 0) goto LAB_00156846;
              }
              if ((sVar8 != 0) && (piVar5 = __errno_location(), *piVar5 != 4)) goto LAB_0015684c;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
            if (sVar8 < 0) {
LAB_0015684c:
              if (((((*(int *)(iVar2 + -0x34) != -1) &&
                    (iVar7 = __fxstat(3,*(int *)(iVar2 + -0x34),&local_80), iVar7 != -1)) &&
                   (*(int *)(iVar2 + -0x28) == local_80.st_dev._4_4_ &&
                    *(int *)(iVar2 + -0x2c) == (int)local_80.st_dev)) &&
                  ((*(__ino_t *)(iVar2 + -0x24) == local_80.st_ino &&
                   (((local_80.st_mode ^ *(uint *)(iVar2 + -0x20)) & 0xfffffe00) == 0)))) &&
                 (*(int *)(iVar2 + -0x18) == local_80.st_rdev._4_4_ &&
                  *(int *)(iVar2 + -0x1c) == (int)local_80.st_rdev)) {
                close(*(int *)(iVar2 + -0x34));
              }
              *(undefined4 *)(iVar2 + -0x34) = 0xffffffff;
            }
            else {
LAB_00156846:
              if (keep_random_devices_open == 0) goto LAB_0015684c;
            }
            __nbytes = rand_pool_bytes_needed(param_1,1);
          }
        }
        uVar10 = uVar10 + 1;
        sVar9 = __nbytes;
        if (__nbytes != 0) {
          sVar9 = 1;
        }
        if (3 < uVar10) {
          sVar9 = 0;
        }
        iVar2 = iVar2 + 0x20;
      } while (sVar9 != 0);
    }
    iVar2 = rand_pool_entropy_available(param_1);
    if (iVar2 != 0) {
      return;
    }
  }
  rand_pool_entropy_available(param_1);
  return;
}

