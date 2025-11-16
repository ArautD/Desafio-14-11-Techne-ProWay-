#include <iostream>
#include <vector>
#include <string>
#include <locale.h>


class Usuario {
private:
    std::string nome;
    std::string email;
public:
    Usuario(const std::string& nome, const std::string& email)
        : nome(nome), email(email) {}

    std::string getNome() const { return nome; }
    std::string getEmail() const { return email; }
};


class UsuarioRepository {
private:
    std::vector<Usuario> usuarios;
public:
    void salvar(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    std::vector<Usuario> listarTodos() const {
        return usuarios;
    }
};


class EmailService {
public:
    void enviarBoasVindas(const Usuario& usuario) {
        std::cout << "Enviando e-mail de boas-vindas para: "
                  << usuario.getEmail() << std::endl;
    }
};


class RelatorioService {
public:
    void gerarRelatorio(const std::vector<Usuario>& usuarios) {
        std::cout << "Relatório de Usuários:" << std::endl;
        for (const auto& u : usuarios) {
            std::cout << "Nome: " << u.getNome()
                      << ", Email: " << u.getEmail() << std::endl;
        }
    }
};


class UsuarioService {
private:
    UsuarioRepository& repository;
    EmailService& emailService;
    RelatorioService& relatorioService;
public:
    UsuarioService(UsuarioRepository& repo, EmailService& email, RelatorioService& relatorio)
        : repository(repo), emailService(email), relatorioService(relatorio) {}

    void cadastrarUsuario(const std::string& nome, const std::string& email) {
        Usuario usuario(nome, email);
        repository.salvar(usuario);
        emailService.enviarBoasVindas(usuario);
    }

    void gerarRelatorioUsuarios() {
        relatorioService.gerarRelatorio(repository.listarTodos());
    }
};

//Frete
class IFrete {
    public: 
    virtual double calcular(double valor) const = 0;
    virtual ~IFrete() = default;
};

class FreteNormal : public IFrete{
    public:
        double calcular(double valor) const override{
            return valor * 0.05;
        }
};

class FreteExpresso : public IFrete{
    public:
        double calcular(double valor) const override{
            return valor * 0.10;
        }
};

class Pedido{
    private:
        double valor;
        const IFrete& frete;
    public:
        Pedido(double valor, const IFrete& frete) : valor(valor), frete(frete){}

        double calcularFrete() const{
            return frete.calcular(valor);
        }
};

class Cartao {
public:
    virtual bool autorizarPagamento(double valor) = 0;
    virtual double consultarLimite() const = 0;
    virtual ~Cartao() = default;
};

class CartaoCredito : public Cartao {
private:
    double limite;
public:
    CartaoCredito(double limite) : limite(limite) {}
    bool autorizarPagamento(double valor) override {
        if (valor <= limite) {
            limite -= valor;
            return true;
        }
        return false;
    }
    double consultarLimite() const override {
        return limite;
    }
};

class CartaoDebito : public Cartao {
private:
    double saldo;
public:
    CartaoDebito(double saldo) : saldo(saldo) {}
    bool autorizarPagamento(double valor) override {
        if (valor <= saldo) {
            saldo -= valor;
            return true;
        }
        return false;
    }
    double consultarLimite() const override {
        return saldo;
    }
};

class IReproduzMusica {
public:
    virtual void reproduzirMusica() = 0;
    virtual ~IReproduzMusica() = default;
};

class IReproduzVideo {
public:
    virtual void reproduzirVideo() = 0;
    virtual ~IReproduzVideo() = default;
};

class IGravaAudio {
public:
    virtual void gravarAudio() = 0;
    virtual ~IGravaAudio() = default;
};

// Classes implementam apenas o que precisam
class PlayerMusicaSimples : public IReproduzMusica {
public:
    void reproduzirMusica() override { std::cout << "Tocando música...\n"; }
};

class GravadorDeAudio : public IGravaAudio {
public:
    void gravarAudio() override { std::cout << "Gravando áudio...\n"; }
};


#include <memory>

class INotificador {
public:
    virtual void enviar(const std::string& msg) = 0;
    virtual ~INotificador() = default;
};

class NotificadorEmail: public INotificador {
public:
    void enviar(const std::string& msg) override {
        std::cout << "Enviando e-mail: " << msg << std::endl;
    }
};

class SmsService : public INotificador {
public:
    void enviar(const std::string& msg) override {
        std::cout << "Enviando SMS: " << msg << std::endl;
    }
};

class NotificacaoService {
private:
    INotificador& notificador;
public:
    NotificacaoService(INotificador& notificador) : notificador(notificador) {}
    void notificar(const std::string& msg) {
        notificador.enviar(msg);
    }
};



int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");


    UsuarioRepository repository;
    EmailService emailService;
    RelatorioService relatorioService;

    UsuarioService usuarioService(repository, emailService, relatorioService);

    system("cls");
    
    usuarioService.cadastrarUsuario("Paulo", "paulo@email.com");
    usuarioService.cadastrarUsuario("lariane", "Lariane@email.com");
    std::cout << "\n" << std::endl;
    usuarioService.gerarRelatorioUsuarios();

    std::cout << "\n--- OCP ---\n";
    // ------------------ OCP ------------------
    FreteNormal freteNormal;
    FreteExpresso freteExpresso;

    Pedido pedido1(100.0, freteNormal);
    Pedido pedido2(100.0, freteExpresso);

    std::cout << "Frete normal: " << pedido1.calcularFrete() << std::endl;
    std::cout << "Frete expresso: " << pedido2.calcularFrete() << std::endl;

    std::cout << "\n--- LSP ---\n";
    // ------------------ LSP ------------------
    CartaoCredito cartaoCredito(500.0);
    CartaoDebito cartaoDebito(300.0);

    Cartao* cartao = &cartaoCredito;
    if (cartao->autorizarPagamento(200.0)) {
        std::cout << "Pagamento autorizado no crédito. Limite restante: "
                  << cartao->consultarLimite() << std::endl;
    }

    cartao = &cartaoDebito;
    if (cartao->autorizarPagamento(100.0)) {
        std::cout << "Pagamento autorizado no débito. Saldo restante: "
                  << cartao->consultarLimite() << std::endl;
    }

    std::cout << "\n--- ISP ---\n";
    // ------------------ ISP ------------------
    PlayerMusicaSimples player;
    GravadorDeAudio gravador;

    player.reproduzirMusica();
    gravador.gravarAudio();

    std::cout << "\n--- DIP ---\n";
    // ------------------ DIP ------------------
    NotificadorEmail emailNotificador; // cuidado: aqui é o EmailService que implementa INotificador
    SmsService smsNotificador;

    NotificacaoService notificacaoEmail(emailNotificador);
    notificacaoEmail.notificar("Bem-vindo ao sistema!");

    NotificacaoService notificacaoSms(smsNotificador);
    notificacaoSms.notificar("Seu código de verificação é 1234");

    return 0;
}
