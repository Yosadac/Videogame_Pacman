#!/bin/bash

# Busca los procesos que están utilizando el puerto 2000
processes=$(sudo lsof -i :2000 | awk 'NR>1 {print $2}')

# Verifica si se encontraron procesos
if [ -z "$processes" ]; then
  echo "No se encontraron procesos utilizando el puerto 2000."
  exit 0
fi

# Recorre los procesos y los finaliza usando kill -9
for pid in $processes; do
  sudo kill -9 $pid
done

echo "Procesos finalizados exitosamente."

exit 0

