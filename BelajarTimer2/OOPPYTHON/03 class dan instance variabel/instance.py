class hewan:
  jumlahHewan=0 #class variabel
  def __init__(self,inputWarna,inputBerkembangbiak,inputBeratBadan):#construktor
    #instance variabel/aribut variabel
    self.warna=inputWarna
    self.berkembangbiak=inputBerkembangbiak
    self.beratBadan=inputBeratBadan
    hewan.jumlahHewan +=1
#setiap kali proses init dijalankan maka hewan.jumlahHewan akan selalu bertambah 1

gajah=hewan("abu-abu","beranak",200)
print("gajah =",gajah.__dict__)
print("jumah Hewan",hewan.jumlahHewan,"=",hewan.jumlahHewan,"hewan")

macan=hewan("putih-hitam-orange","beranak",75)
print("macan =",macan.__dict__)
print("jumah Hewan",hewan.jumlahHewan,"=",hewan.jumlahHewan,"hewan")

panda=hewan("hitam-putih","beranak",90)
print("panda =",panda.__dict__)
print("jumah Hewan",hewan.jumlahHewan,"=",hewan.jumlahHewan,"hewan")