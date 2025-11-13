module Mahasiswa where

-- TYPE MAHASISWA
-- DEFINISI TYPE
-- type mahasiswa: <nama: String, nim: String, ipk: Float>
-- {<nama, nim, ipk> adalah sebuah mahasiswa, dengan nama adalah nama mahasiswa,
--  nim adalah nomor induk mahasiswa, ipk adalah nilai IPK mahasiswa}

data Mahasiswa = Mahasiswa String String Float
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- nama: mahasiswa -> String
-- {nama(M) memberikan nama Mahasiswa M}
nama :: Mahasiswa -> String
-- TODO
nama (Mahasiswa nama _ _) = nama  

-- nim: mahasiswa -> String
-- {nim(M) memberikan NIM Mahasiswa M}
nim :: Mahasiswa -> String 
-- TODO
nim (Mahasiswa _ nim _) = nim 

-- ipk: mahasiswa -> Float
-- {ipk(M) memberikan IPK Mahasiswa M}
ipk :: Mahasiswa -> Float
-- TODO
ipk (Mahasiswa _ _ ipk) = ipk  

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeMahasiswa: String -> String -> Float -> mahasiswa
-- {makeMahasiswa(nama,nim,ipk) membentuk Mahasiswa baru}
makeMahasiswa :: String -> String -> Float -> Mahasiswa
-- TODO
makeMahasiswa nama nim ipk = Mahasiswa nama nim ipk

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isValidMahasiswa: mahasiswa -> boolean
-- {isValidMahasiswa(M) benar jika M memiliki Nama, NIM tidak kosong dan IPK antara 0.0 s.d. 4.0}
isValidMahasiswa :: Mahasiswa -> Bool
-- TODO
isValidMahasiswa mahasiswa =
  nama mahasiswa /= "" && nim mahasiswa /= "" && ipk mahasiswa >= 0.0 && ipk mahasiswa <= 4.0

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP MAHASISWA
-- gantiIPK: mahasiswa -> Float -> mahasiswa
-- {gantiIPK(M,ipkBaru) mengganti IPK mahasiswa M dengan ipkBaru (maksimal 4.0)}
gantiIPK :: Mahasiswa -> Float -> Mahasiswa
-- TODO
gantiIPK mahasiswa ipkBaru
  | ipkBaru <= 0 = makeMahasiswa (nama mahasiswa) (nim mahasiswa) 0
  | ipkBaru >= 4 = makeMahasiswa (nama mahasiswa) (nim mahasiswa) 4
  | otherwise = makeMahasiswa (nama mahasiswa) (nim mahasiswa) (ipkBaru)

-- klasifikasiMahasiswa: mahasiswa -> String
-- {klasifikasiMahasiswa(M) memberikan predikat mahasiswa berdasarkan IPK}
-- Dengan ketentuan:
-- IPK >= 3.51 : "Cumlaude"
-- 3.00 <= IPK < 3.51 : "Sangat Memuaskan"
-- 2.75 <= IPK < 3.00 : "Memuaskan"
-- IPK < 2.75 : "Perlu Perbaikan"
klasifikasiMahasiswa :: Mahasiswa -> String
-- TODO
klasifikasiMahasiswa mahasiswa =
  if (ipk mahasiswa >= 3.51) then "Cumlaude"
  else if (ipk mahasiswa >= 3.00 && ipk mahasiswa < 3.51) then "Sangat Memuaskan"
  else if (ipk mahasiswa >= 2.75 && ipk mahasiswa < 3.00) then "Memuaskan"
  else "Perlu Perbaikan"

-- tampilMahasiswa: mahasiswa -> String
-- {tampilMahasiswa(M) mengubah Mahasiswa M menjadi string deskriptif}
-- Dengan format:
-- "Nama: <nama>, NIM: <nim>, IPK: <ipk>"
tampilMahasiswa :: Mahasiswa -> String
-- TODO
tampilMahasiswa mahasiswa =
  "Nama: " ++ (nama mahasiswa) ++ ", NIM: " ++ (nim mahasiswa) ++ ", IPK: " ++ show (ipk mahasiswa)