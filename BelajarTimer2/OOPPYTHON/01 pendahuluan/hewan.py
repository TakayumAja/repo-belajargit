class hewan: #tampalate atau cetakkan 
  pass


gajah=hewan()#object atau intance
macan=hewan()
panda=hewan()
 
gajah.warna="abu-abu"
gajah.bekembangbiak="beranak"
gajah.berat=500

macan.warna="puthi-hitam-oren"
macan.berkembangbiak="beranak"
macan.berat=75

panda.warna="putih-hitam"
panda.berkembangbiak="beranak"
panda.berat=90
#panda.berkembangbiak="bertelur"

print(gajah.__dict__)
print(macan.__dict__)
print(panda.__dict__)