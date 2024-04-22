
void env_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  int chainid;
  int sensorid;
  
  strcpy(runtime->asic_name,app_conf->name);
  iVar1 = calc_asic_addr_interval(app_conf->asic_num);
  runtime->addr_interval = iVar1;
  runtime->sensor_num = app_conf->sensor_num;
  for (sensorid = 0; sensorid < app_conf->sensor_num; sensorid = sensorid + 1) {
    runtime->sensor_pos[sensorid] = app_conf->sensor_pos[sensorid];
  }
  runtime->chain_num = app_conf->comport_num;
  for (chainid = 0; chainid < runtime->chain_num; chainid = chainid + 1) {
    runtime->chain_status[chainid].comport = app_conf->comport[chainid];
    runtime->chain_status[chainid].design_asic_num = app_conf->asic_num;
  }
  runtime->baudrate = app_conf->baudrate;
  runtime->nonce_shift = 0x14;
  bm174x_init_asic(runtime);
  equihash_init_algo(runtime);
  equihash_miner_init(runtime);
  return;
}

