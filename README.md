# Implementing Secure Access Control: Bell-LaPadula Model  

## 📌 About the Project  
This project focuses on **the implementation of the Bell-LaPadula security model** in a **Linux-based environment**, enforcing strict **confidentiality policies**.  
The objective is to configure a **secure system** where **classified data remains protected**, ensuring that unauthorized users cannot read or modify sensitive information.  

The implementation involves **user permissions, encryption mechanisms, and controlled access programs** to maintain **data confidentiality**.  

---

## 🛠 Technologies Used  
- **Linux Ubuntu** (Security Configuration & User Management)  
- **Access Control Tools** (`chmod`, `chown`, `useradd`, `groupadd`)  
- **Asymmetric Encryption** (`openssl`, `ssh-keygen`, `gpg`)  
- **Setuid Programs** (Controlled Access Applications)  

---

## 📂 Security Implementation  

### **1️⃣ System Configuration**  
✔ **User & Group Creation** → Defines security levels (**high, medium, low**)  
✔ **Directory & File Permissions** → Implements **read/write restrictions** based on the Bell-LaPadula model  
✔ **Access Control Policies** → Defines **who can access, modify, and execute** system resources  

### **2️⃣ Bell-LaPadula Model Implementation**  

🔒 **Key Security Rules**  
- **"No Read Up" (NRU)** → Low-level users **cannot read** high-level data  
- **"No Write Down" (NWD)** → High-level users **cannot write** to lower levels  
- Ensures **data confidentiality**, preventing unauthorized access to classified files  

### **3️⃣ Asymmetric Encryption**  
✔ **Public & Private Key Generation** → Secures file storage and transmission  
✔ **Encryption & Decryption** → Protects sensitive files from unauthorized access  
✔ **File Sharing Restrictions** → Ensures only authorized users can decrypt critical data  

### **4️⃣ Restricted Query Program**  
✔ Implements **setuid execution** to allow controlled access  
✔ Restricts **file reading based on permission rules**  
✔ Protects against **path traversal attacks & unauthorized queries**  

---

