
int json_real_equal(json_t *real1,json_t *real2)

{
  double dVar1;
  double dVar2;
  json_t *real2_local;
  json_t *real1_local;
  
  dVar1 = json_real_value(real1);
  dVar2 = json_real_value(real2);
  return (uint)(dVar1 == dVar2);
}

