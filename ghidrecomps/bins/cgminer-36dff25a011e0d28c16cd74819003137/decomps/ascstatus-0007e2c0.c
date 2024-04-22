
void ascstatus(io_data *io_data,int asc,_Bool isjson,_Bool precom)

{
  uint uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  _Bool precom_local;
  _Bool isjson_local;
  int asc_local;
  io_data *io_data_local;
  double rejp;
  double hwp;
  int last_share_pool;
  char mhsname [27];
  double mhs;
  double dev_runtime;
  float temp;
  char *status;
  cgpu_info *cgpu;
  int dev;
  int numasc;
  api_data *root;
  char *enabled;
  
  root = (api_data *)0x0;
  asc_local = asc;
  io_data_local = io_data;
  numasc = numascs();
  if ((((0 < numasc) && (-1 < asc_local)) && (asc_local < numasc)) &&
     (dev = ascdevice(asc_local), -1 < dev)) {
    cgpu = get_devices(dev);
    temp = (float)cgpu->temp;
    dev_runtime = cgpu_runtime(cgpu);
    cgpu->utility = ((double)(longlong)cgpu->accepted / dev_runtime) * DAT_0007e770;
    if (cgpu->deven == DEV_DISABLED) {
      enabled = NO;
    }
    else {
      enabled = YES;
    }
    status = status2str(cgpu->status);
    root = api_add_int(root,"ASC",&asc_local,false);
    root = api_add_string(root,"Name",cgpu->drv->name,false);
    root = api_add_int(root,"ID",&cgpu->device_id,false);
    root = api_add_string(root,"Enabled",enabled,false);
    root = api_add_string(root,"Status",status,false);
    root = api_add_temp(root,"Temperature",&temp,false);
    mhs = cgpu->total_mhashes / dev_runtime;
    root = api_add_mhs(root,"MHS av",&mhs,false);
    sprintf(mhsname,"MHS %ds",opt_log_interval);
    root = api_add_mhs(root,mhsname,&cgpu->rolling,false);
    root = api_add_int(root,"Accepted",&cgpu->accepted,false);
    root = api_add_int(root,"Rejected",&cgpu->rejected,false);
    root = api_add_int(root,"Hardware Errors",&cgpu->hw_errors,false);
    root = api_add_utility(root,"Utility",&cgpu->utility,false);
    if (cgpu->last_share_pool_time < 1) {
      last_share_pool = -1;
    }
    else {
      last_share_pool = cgpu->last_share_pool;
    }
    root = api_add_int(root,"Last Share Pool",&last_share_pool,false);
    root = api_add_time(root,"Last Share Time",&cgpu->last_share_pool_time,false);
    root = api_add_mhtotal(root,"Total MH",&cgpu->total_mhashes,false);
    root = api_add_int64(root,"Diff1 Work",&cgpu->diff1,false);
    root = api_add_diff(root,"Difficulty Accepted",&cgpu->diff_accepted,false);
    root = api_add_diff(root,"Difficulty Rejected",&cgpu->diff_rejected,false);
    root = api_add_diff(root,"Last Share Difficulty",&cgpu->last_share_diff,false);
    root = api_add_time(root,"Last Valid Work",&cgpu->last_device_valid_work,false);
    uVar1 = cgpu->hw_errors;
    hwp = DAT_0007e778;
    if ((uVar1 + *(uint *)&cgpu->diff1 |
        ((int)uVar1 >> 0x1f) + *(int *)((int)&cgpu->diff1 + 4) +
        (uint)CARRY4(uVar1,*(uint *)&cgpu->diff1)) != 0) {
      iVar2 = cgpu->hw_errors;
      uVar1 = cgpu->hw_errors;
      dVar3 = (double)__aeabi_l2d(uVar1 + *(uint *)&cgpu->diff1,
                                  ((int)uVar1 >> 0x1f) + *(int *)((int)&cgpu->diff1 + 4) +
                                  (uint)CARRY4(uVar1,*(uint *)&cgpu->diff1));
      hwp = (double)(longlong)iVar2 / dVar3;
    }
    root = api_add_percent(root,"Device Hardware%",&hwp,false);
    rejp = DAT_0007e778;
    if ((*(uint *)&cgpu->diff1 | *(uint *)((int)&cgpu->diff1 + 4)) != 0) {
      dVar4 = cgpu->diff_rejected;
      dVar3 = (double)__aeabi_l2d(*(undefined4 *)&cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4)
                                 );
      rejp = dVar4 / dVar3;
    }
    root = api_add_percent(root,"Device Rejected%",&rejp,false);
    root = api_add_elapsed(root,"Device Elapsed",&dev_runtime,false);
    print_data(io_data_local,root,isjson,precom);
  }
  return;
}

