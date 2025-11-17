# 📘 Projeto C++ - Princípios SOLID

Este projeto em C++ demonstra a aplicação dos **princípios SOLID** através de um sistema modular com funcionalidades como cadastro de usuários, envio de notificações, cálculo de frete, autorização de pagamentos e reprodução de mídia.

---

## 📂 Estrutura do Projeto

O código está organizado em classes que representam diferentes responsabilidades:

- **Usuario / UsuarioRepository / UsuarioService**  
  Cadastro e gerenciamento de usuários, envio de e-mails e geração de relatórios.

- **FreteNormal / FreteExpresso / Pedido**  
  Cálculo de frete com base em tipos diferentes, aplicando o princípio OCP.

- **CartaoCredito / CartaoDebito**  
  Autorização de pagamentos com cartões, aplicando o princípio LSP.

- **PlayerMusicaSimples / GravadorDeAudio**  
  Interfaces segregadas para reprodução de música e gravação de áudio (ISP).

- **NotificadorEmail / SmsService / NotificacaoService**  
  Sistema de notificações desacoplado por injeção de dependência (DIP).

---

## 📜 Funcionamento

Ao executar o programa, são realizadas as seguintes ações:

1. Cadastro de dois usuários com envio de e-mail de boas-vindas.
2. Geração de relatório com os dados dos usuários.
3. Demonstração do cálculo de frete normal e expresso.
4. Autorização de pagamentos com cartão de crédito e débito.
5. Reprodução de música e gravação de áudio.
6. Envio de notificações por e-mail e SMS.

Cada bloco do programa é precedido por um título que indica o princípio SOLID sendo demonstrado:

- `--- OCP ---` → Open/Closed Principle  
- `--- LSP ---` → Liskov Substitution Principle  
- `--- ISP ---` → Interface Segregation Principle  
- `--- DIP ---` → Dependency Inversion Principle  

---

## 🚀 Como Executar

1. Compile o arquivo principal:
   ```bash
   g++ main.cpp -o solid_demo
   ```

2. Execute o programa:
   ```bash
   ./solid_demo
   ```

---

## 🎯 Conceitos Utilizados

- **SOLID**  
  - OCP: Classes de frete abertas para extensão, fechadas para modificação.  
  - LSP: Cartões podem ser usados de forma intercambiável.  
  - ISP: Interfaces específicas para funcionalidades distintas.  
  - DIP: Serviços dependem de abstrações, não de implementações concretas.

- **POO e Encapsulamento**  
  - Uso de classes, métodos públicos e privados.  
  - Separação de responsabilidades por classe.

- **Vetores e ponteiros**  
  - Uso de `std::vector` para armazenar objetos.  
  - Uso de ponteiros e referências para abstração.

---

## 🧑‍💻 Autores

Projeto desenvolvido como exercício de aplicação dos **princípios SOLID em C++**.  
Ideal para estudos de arquitetura orientada a objetos e boas práticas de design.
