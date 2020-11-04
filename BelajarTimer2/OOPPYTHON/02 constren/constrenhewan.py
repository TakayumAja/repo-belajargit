class hewan:
  def __init__(self,inputWarna,inputBerkembangbiak,inputBeratBadan):#construktor
    #instance variabel/atribut variabel
    self.warna=inputWarna
    self.berkembangbiak=inputBerkembangbiak
    self.beratBadan=inputBeratBadan
#construktor akan berjalan jika dibawahnya diisi dengan suatu object/intance


gajah=hewan("abu-abu","beranak",200)
print("gajah =",gajah.__dict__)

macan=hewan("putih-hitam-orange","beranak",75)
print("macan =",macan.__dict__)

panda=hewan("hitam-putih","beranak",90)
print("panda =",panda.__dict__)

#__dict__ adalah keyword didalam python untuk menyebutkan atribut apa saja yang dimiliki oleh object