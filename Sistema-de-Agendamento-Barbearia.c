#include <stdio.h>
#include <string.h>

struct Usuario// STRUCTS
{
    char nome[20];
    char senha[20];
};

struct Cadastro
{
    char usuario[50][20];
    char password[50][20];
};

struct Admin
{
    char nome[20];
    char senha[20];
};

struct Pedido
{
    char barbeiro[50][20];
    char cliente[50][20];
    char corte[50][20];
    char dia[50][20];
    char hora[50][20];
    char pagamento[50][20];
};


int main()
{
    void escolherHorario(int escolher_horario, const char HORAS[22][30], struct Pedido *pd, int id_cliente);
    int Remover(int id_cliente,int seat_chose[50], struct Pedido *pd);
    void escolherDia(int escolher_dia, const char DIAS[7][30], struct Pedido *pd, int id_cliente);
    int verificarHorarioEscolhido(int escolher_horario, const char HORAS[22][30], int seat_chose[50]);

    const char USUARIO_BARBEIRO[3][20] = {"","pedro","marcos"};//constantes com credeencias de barbeiro
    const char SENHA_BARBEIRO[3][20] = {"","1234","12345"};

    int sair = 0;// VARIÁVEIS DECLARADAS
    int opcao = 0;
    int Total_usuario = 0;
    int escolher_corte = 0;
    int escolher_barbeiro = 0;
    int escolher_dia;
    int escolher_horario;
    int i;
    int autentica = 0;
    int pagamento = 0;
    int finalizar_sair = 0;
    int receber_cliente = 0;
    int gerencia_agendamento = 0;
    int agendamento_confirmado = 0;
    int agendamento_reagendado = 0;
    int agendamento_cancelado = 0;
    int seat_chose[50] = {0};
    int g = 0;
    int receber_id;
    int novo_total_clientes = 0;
    int pedido_por_cliente = 0;


    const char DIAS[7][30] = {"Segunda-Feira","Terça-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira","Sábado","Domingo"};//constantes de dias e horas
    const char HORAS[22][30] = {"8:00","8:30","9:00","9:30","10:00","10:30","11:00","11:30","12:00","14:00","14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:00","18:30"};
    
    struct Usuario user;// STRUCTS DECLARADO
    struct Cadastro cd = {0};
    struct Admin ad;
    struct Pedido pd;

    while(sair == 0)// LAÇO DE INICIO DO PROGRAMAR
    {

        printf("(1)- Fazer Login\n");
        printf("(2)- Cadastra-se\n");
        printf("(3)- Login do funcionario\n");
        scanf("%d", &opcao);
        while(getchar() != '\n');
              
        while(opcao != 1 && opcao != 2 && opcao != 3)// LAÇO DE VALIDAR OPÇÕES
        {
            printf("Digite uma opção valida\n\n");
            printf("(1)- Fazer Login\n");
            printf("(2)- Cadastra-se\n");
            printf("(3)- Login do funcionario\n");
            scanf("%d", &opcao);
            while(getchar() != '\n');
        }
            if(opcao == 1)// OPÇÃO 1
            {
                while(sair == 0)// LAÇO PRINCIPAL DA OPÇÃO 1
                {
                    printf("Digite o Seu Nome:\n");//INPUT DE NOME
                    fgets(user.nome,20, stdin);
                    user.nome[strcspn(user.nome, "\n")] = 0;
                    
                    printf("Digite o Sua Senha:\n");//INPUT DE SENHA
                    fgets(user.senha,20, stdin);
                    user.senha[strcspn(user.senha, "\n")] = 0;

                    printf("(1)- Entrar\n");
                    printf("(2)- Voltar\n");
                    scanf("%d", &autentica);
                    while(getchar() != '\n');
                    
                    while(autentica != 1 && autentica != 2)//opção de autetnicar ou sair ?
                    {
                        printf("(1)- Entrar\n");
                        printf("(2)- Voltar\n");
                        scanf("%d", &autentica);
                        while(getchar() != '\n');
                    }

                    if(autentica == 2){break;}// voltar

                    int verificar_user = 0;
                    
                    for(int i = 0; i < Total_usuario; i++)//VERIFICANDO SE EXISTE O USUÁRIO
                    {
                       
                        if(strcmp(user.nome, cd.usuario[i]) == 0 && strcmp(user.senha, cd.password[i]) == 0)//login do usuário
                        {
                             verificar_user = 1;
         
                            if(agendamento_confirmado >= 1)// feedback de pedido confirmado
                            {
                                printf("Seu pedido foi confirmado!\n");
                                agendamento_confirmado = 0;
                            }

                            if(agendamento_reagendado >= 1)// feedback de pedido reagendado
                            {
                                printf("Seu pedido foi Reagendado!\n");
                                
                                printf("Novo Dia: %s\n", pd.dia[receber_id]);
                                printf("Novo Hora: %s\n", pd.hora[receber_id]);

                               novo_total_clientes = Remover(receber_id,seat_chose, &pd);

                                if(novo_total_clientes < 0)
                                {
                                    novo_total_clientes = 0;
                                }

                                agendamento_reagendado = 0;
                            }

                            if(agendamento_cancelado >= 1)// feedback de pedido cancelado
                            {
                                printf("Seu pedido foi Cancelado!\n");
                                agendamento_cancelado = 0;
                            }


                                int opcao_pedido = 0;
                                 int opcao_novo_agendamento = 0;
                                while(pedido_por_cliente == 1)
                                {
                                    printf("Você já tem um agendamento em pendente\n");
                                    printf("(1)- Cancelar agendamento anterior\n");
                                    printf("(2)- Sair\n");
                                    scanf("%d",&opcao_pedido);
                                    while(getchar() != '\n');

                                    if(opcao_pedido == 1)
                                    {
                                        printf("Agendamento Cancelado\n\n");
                                        printf("(1)- fazer novo agendamento\n");
                                        printf("(2)-  sair\n");
                                        scanf("%d", &opcao_novo_agendamento);
                                        while(getchar() != '\n');

                                        while (opcao_novo_agendamento != 1 && opcao_novo_agendamento != 2)
                                        {
                                            scanf("%d", &opcao_novo_agendamento);
                                            while(getchar() != '\n');
                                        }

                                        pedido_por_cliente = 0;
                                        novo_total_clientes -= 1;
                                        break;
                                    }

                                    if(opcao_pedido == 2){sair = 1; break;}
                                }

                                if(opcao_novo_agendamento == 2){sair = 1; break;}

                                if(opcao_pedido == 2){break;}
                            
                                strcpy(pd.cliente[i], user.nome);// armazenando o nome do cliente 

                                printf("===================ESCOLHAR UM CORTE====================\n\n");
                               printf("(1) Corte 15$\n");
                               printf("(2) Barba 5$\n");
                               printf("(3)Corte + Barba 20$\n");
                               scanf("%d", &escolher_corte);
                               while(getchar() != '\n');
                               
                               while(escolher_corte != 1 && escolher_corte != 2 && escolher_corte != 3)//validando as opções de cortes
                               {
                                   printf("(1) Corte 15$\n");
                                   printf("(2) Barba 5$\n");
                                   printf("(3)Corte + Barba 20$\n");
                                   scanf("%d", &escolher_corte);
                                   while(getchar() != '\n');
                               }

                               switch(escolher_corte)// condiconal que armazena o tipo de corte escolhido
                               {
                                    case 1:
                                        strcpy(pd.corte[i], "Corte 15$");
                                    break;
                                        case 2:
                                            strcpy(pd.corte[i], "Barba 5$");
                                        break;
                                            case 3:
                                                strcpy(pd.corte[i], "Corte + Barba 20$");
                                            break;
                               }

                               printf("===================ESCOLHAR UM BARBEIRO====================\n\n");

                               printf("(1) Pedro\n");
                               printf("(2) Marcos\n");
                               scanf("%d", &escolher_barbeiro);
                                while(getchar() != '\n');

                                while(escolher_barbeiro != 1 && escolher_barbeiro != 2)//validando as opções de barbeiros
                               {
                                   printf("(1) Pedro\n");
                                    printf("(2) Marcos\n");
                                    scanf("%d", &escolher_barbeiro);
                                     while(getchar() != '\n');
                               }

                               switch(escolher_barbeiro)// condiconal que armazena o barbeiro escolhido
                               {
                                    case 1:
                                        strcpy(pd.barbeiro[i], "pedro");
                                    break;
                                        case 2:
                                            strcpy(pd.barbeiro[i], "marcos");
                                        break;                         
                               }

                              
                               printf("===================ESCOLHAR UM DIA====================\n\n");

                               for(int day = 0; day < 7; day++)// listagem de dias
                               {
                                    printf("%d %s\n",day+1, DIAS[day]);
                               }

                               scanf("%d", &escolher_dia);
                               while(getchar() != '\n');

                                while(escolher_dia > 7 || escolher_dia == 0)//validando as opções de dias
                                {
                                    for(int day = 0; day < 7; day++)
                                    {
                                       printf("%d %s\n",day+1, DIAS[day]);
                                    }

                                    scanf("%d", &escolher_dia);
                                     while(getchar() != '\n');
                                }


                               escolherDia( escolher_dia, DIAS, &pd,  i);// função de escolher dia
                             
                               printf("===================ESCOLHAR UM HORÁRIO====================\n\n");

                               for(int time = 0; time < 19; time++)// listagem de horário
                               {
                                    printf("%d %s\n",time+1, HORAS[time]);
                               }

                               scanf("%d", &escolher_horario);
                               while(getchar() != '\n');
                                
                                while(escolher_horario > 19 || escolher_horario == 0)// validando opções de horário
                                {
                                    for(int time = 0; time < 19; time++)
                                    {
                                       printf("%d %s\n",time+1, HORAS[time]);
                                    }

                                    scanf("%d", &escolher_horario);
                                     while(getchar() != '\n');
                                }
                                
                                 int escolher_horario_certo = verificarHorarioEscolhido( escolher_horario,HORAS, seat_chose); //função de verificar horário escolhidos
                                
                                seat_chose[g] = escolher_horario_certo;// array armazenando horários escolhidos
                                g++;

                                escolherHorario( escolher_horario_certo, HORAS, &pd, i);  // função de escolher um horário  

                                printf("Deseja confirmar o agendamento?\n");
                                printf("(1) Confirmar\n");
                                printf("(2) Cancelar\n");
                                scanf("%d", &finalizar_sair);
                                
                                while(finalizar_sair != 1 && finalizar_sair != 2)//validando opções de confirmação e de cancelamento
                                {
                                    printf("Deseja confirmar o agendamento?\n");
                                    printf("(1) Confirmar\n");
                                    printf("(2) Cancelar\n");
                                    scanf("%d", &finalizar_sair);
                                }

                                if(finalizar_sair == 2)//cancelar o agendamento
                                {
                                    novo_total_clientes = Remover(i,seat_chose, &pd);

                                        if(novo_total_clientes < 0)
                                        {
                                            novo_total_clientes = 0;
                                        }

                                    sair = 1;
                                    break;
                                }

                                
                                 printf("===================FORMAR DE PAGAMENTO====================\n\n");

                                printf("(1) pix\n");
                                printf("(2) espécie\n");
                                scanf("%d", &pagamento);
                                while(getchar() != '\n');  
                                
                                while(pagamento != 1 && pagamento != 2)//validando opção de pagamentos
                                {
                                    printf("(1) pix\n");
                                    printf("(2) espécie\n");
                                    scanf("%d", &pagamento);
                                    while(getchar() != '\n');
                                }

                                switch(pagamento)// Condição aonde o arrays pagamento vão recebendo o tipo de pagamento
                                {
                                    case 1:
                                        strcpy(pd.pagamento[i], "pix");
                                    break;
                                        case 2:
                                            strcpy(pd.pagamento[i], "espécie");
                                        break;
                                }
                                
                                printf("(1) Confirmar Agendamento\n");
                                printf("(2) Cancelar\n");
                                scanf("%d", &finalizar_sair);
                                while(getchar() != '\n');

                                while(finalizar_sair != 1 && finalizar_sair != 2)// validando opções de cancelamento e confirmação
                                {
                                    printf("Deseja confirmar o agendamento?\n");
                                    printf("(1) Confirmar Agendamento\n");
                                    printf("(2) Cancelar\n");
                                    scanf("%d", &finalizar_sair);
                                    while(getchar() != '\n');
                                }
                                
                                if(finalizar_sair == 2)//cancelar o agendamento
                                {
                                    novo_total_clientes = Remover(i,seat_chose, &pd);

                                     if(novo_total_clientes < 0)
                                      {
                                         novo_total_clientes = 0;
                                      }
                                    sair = 1; 
                                    break;
                                }

                                if(finalizar_sair == 1)// se o agendamneto for confirmado
                                {
                                    novo_total_clientes += 1;
                                }

                                receber_cliente = novo_total_clientes;
                                
                                int fim_agendamento = 0;

                                printf("Vai receber confirmação por e-mail\n\n");
                                printf("(1) Sair\n");
                                scanf("%d", &fim_agendamento);
                                while(getchar() != '\n');
                                
                                while(fim_agendamento != 1 ) //validando opção de sair ou fazer um novo agendamneto
                                {
                                    printf("Vai receber confirmação por e-mail\n\n");
                                    printf("(1) Sair\n");
                                    scanf("%d", &fim_agendamento);
                                    while(getchar() != '\n');
                                }
                                
                                pedido_por_cliente = 1;
                                if(fim_agendamento == 1){ sair = 1; break;}// Sair do opção de agendamento       
                               
                               
                        } 
                    }
                    
                    if(verificar_user == 0)// se não exister usuário ou for inválido
                    {
                        printf("Usuário inválido\n");
                    }
                    
                }
                sair = 0;
            }
            
                if(opcao == 2) // OPÇÃO 2 Cadastrar novo Cliente
                {
                    while (sair != 1)
                    {
                        for(i = 0; i < sizeof(cd.usuario); i++)
                        {

                            printf("Digite o Seu Nome:\n");//INPUT DE NOME
                            fgets(cd.usuario[i],20, stdin);
                            cd.usuario[i][strcspn(cd.usuario[i], "\n")] = 0;
                        
                            printf("Digite o Sua Senha:\n");//INPUT DE SENHA
                            fgets(cd.password[i],20, stdin);
                            cd.password[i][strcspn(cd.password[i], "\n")] = 0;

                            Total_usuario += 1;

                            printf("Usuário Cadastrado com sucesso\n\n");

                            printf("1- Continuar\n");
                            printf("2- Sair\n");
                            scanf("%d", &sair);
                            while(getchar() != '\n');
                            
                            while (sair != 1 && sair != 2)
                            {
                                printf("1- Continuar\n");
                                printf("2- Sair\n");
                                scanf("%d", &sair);
                                while(getchar() != '\n');
                            }
                            

                            if(sair == 2){sair = 1; break;}
                        }
                    }
                    
                   sair = 0;
                }

                if(opcao == 3)// OPÇÃO 3 Regerenciamento do barbeiro
                {
                    while (sair != 1)// laço de inicio da 3 opção
                    {
                        int existe_barbeiro = 0;

                        printf("Digite seu Nome:\n");
                        fgets(ad.nome, sizeof(ad.nome), stdin);
                        ad.nome[strcspn(ad.nome, "\n")] = 0;

                        printf("Digite sua Senha:\n");
                        fgets(ad.senha, sizeof(ad.senha), stdin);
                        ad.senha[strcspn(ad.senha, "\n")] = 0;

                        for(i = 1; i < 3; i++) // laço para veificar usuário do barbeiro
                        {
   
                            if(strcmp(ad.nome, USUARIO_BARBEIRO[i]) == 0 && strcmp(ad.senha, SENHA_BARBEIRO[i]) == 0)// login do barbeiro
                            {
                                existe_barbeiro = 1;
                                int exister_cliente = 0;

                               for(int init = 0; init < 3; init++)// laço para veificar barbeiro
                               {        

                                   if(strcmp(ad.nome, pd.barbeiro[init]) == 0)// verificando o nome do barbeiro
                                   {
                                       exister_cliente = 1;
                                       receber_cliente = novo_total_clientes;

                                        for(int i = 0; i < receber_cliente; i++)// listagem de todos os agendamento
                                        {
                                            printf("ID: %d\n", i+1);
                                            printf("Cliente: %s\n", pd.cliente[i]);
                                            printf("Corte: %s\n", pd.corte[i]);
                                            printf("Dia: %s\n", pd.dia[i]);
                                            printf("Horário: %s\n", pd.hora[i]);
                                            printf("Formar de Pagamento: %s\n\n", pd.pagamento[i]);
                                        }

                                        printf("(1) Confirmar Agendamento\n");
                                        printf("(2) Reagenda\n");
                                        printf("(3) Cancelar\n");
                                        printf("(4) Sair\n");
                                        scanf("%d", &gerencia_agendamento);
                                        
                                        while(gerencia_agendamento != 1 && gerencia_agendamento != 2 && gerencia_agendamento != 3 && gerencia_agendamento != 4)// validando opções de gerenciamneto
                                        {
                                            printf("(1) Confirmar Agendamento\n");
                                            printf("(2) Reagenda\n");
                                            printf("(3) Cancelar\n");
                                            printf("(4) Sair\n");
                                            scanf("%d", &gerencia_agendamento);

                                        }

                                        if(gerencia_agendamento == 1)// opção de confirmar agendamento
                                        {
                                            int id_cliente = 0;

                                            printf("Digite o ID no cliente\n");
                                            scanf("%d", &id_cliente);

                                            while(id_cliente == 0)
                                            {
                                                scanf("%d", &id_cliente);
                                            }

                                             for(int id = 1; id < 50; id++)
                                             {

                                                 if(id_cliente == id)
                                                 {
                                                    if(id_cliente == 1)
                                                    {
                                                        id_cliente = 0;
                                                        break;
                                                    }
                                                        else
                                                        {
                                                             id_cliente = id-1;
                                                             break;
                                                        }
                                                 }
                                             }
                                            pedido_por_cliente = 0;
                                           novo_total_clientes = Remover(id_cliente,seat_chose, &pd);// função de remover pedido

                                           if(novo_total_clientes < 0)
                                           {
                                              novo_total_clientes = 0;
                                           }

                                             printf("novo total  %d\n", novo_total_clientes);

                                             agendamento_confirmado += 1;
                                             printf("Agendamento confirmado\n");
                                        }

                                        if(gerencia_agendamento == 2)// opção para reagenda dia e horário
                                        {
                                            int id_cliente = 0;
                                            int edit_dateTime = 0;

                                            printf("Digite o ID no cliente\n");
                                            scanf("%d", &id_cliente);

                                             while(id_cliente == 0)
                                            {
                                                scanf("%d\n", &id_cliente);
                                            }

                                             for(int id = 1; id < 50; id++)
                                             {

                                                 if(id_cliente == id)
                                                 {
                                                    if(id_cliente == 1)
                                                    {
                                                        id_cliente = 0;
                                                    }
                                                        else
                                                        {
                                                             id_cliente = id-1;
                                                        }
                                                 }
                                             }

                                              for(int id = id_cliente; id < 50; id++)// listagem de dia e horário do cliente escolhido
                                              {         
                                                printf("Dia: %s\n",pd.dia[id]);
                                                printf("Horario: %s\n",pd.hora[id]);
                                                break;            
                                              }

                                            printf("(1)- Dia\n");
                                            printf("(2)- Hora\n");
                                            scanf("%d", &edit_dateTime);

                                            while(edit_dateTime != 1 && edit_dateTime != 2)//validando opção de reagendamento
                                            {
                                                scanf("%d", &edit_dateTime);
                                            }

                                            if(edit_dateTime == 1)//opção de reagenda um novo dia
                                            {
                                                printf("=================Agende um novo Dia===================\n\n");
                                               
                                                     for(int day = 0; day < 7; day++)// lista de dias
                                                     {
                                                        printf("%d %s\n",day+1, DIAS[day]);
                                                     }

                                                        scanf("%d", &escolher_dia);
                                                        while(getchar() != '\n');

                                                    while(escolher_dia > 7 || escolher_dia == 0)//validação das opções de dia
                                                    {
                                                        for(int day = 0; day < 7; day++)
                                                        {
                                                            printf("%d %s\n",day+1, DIAS[day]);
                                                        }

                                                        scanf("%d", &escolher_dia);
                                                        while(getchar() != '\n');
                                                    }

                                                      escolherDia(escolher_dia, DIAS, &pd, id_cliente);// função de escolher um dia

                                                        agendamento_reagendado += 1;
                                                        printf("Novo Agendamento confirmado\n");  
                                            }


                                            if(edit_dateTime == 2)//opção de reagenda um novo horário
                                            {
                                                printf("=================Agende um nova Hora===================\n\n");

                                                    for(int time = 0; time < 19; time++)// lista de horários
                                                    {
                                                        printf("%d %s\n",time+1, HORAS[time]);
                                                    }

                                                    scanf("%d", &escolher_horario);
                                                    while(getchar() != '\n');

                                                        while(escolher_horario > 19 || escolher_horario == 0)//validando horários
                                                        {
                                                            for(int time = 0; time < 19; time++)
                                                            {
                                                                printf("%d %s\n",time+1, HORAS[time]);
                                                            }

                                                            scanf("%d", &escolher_horario);
                                                            while(getchar() != '\n');
                                                        }

                                                         int escolher_horario_certo = verificarHorarioEscolhido( escolher_horario,HORAS, seat_chose); //função de verificar horário escolhidos

                                                        seat_chose[g] = escolher_horario_certo;// array armazenando horários escolhidos
                                                        g++;

                                                      escolherHorario( escolher_horario_certo,HORAS, &pd, id_cliente);// função de escolher Horário
                                                         
                                                    agendamento_reagendado += 1;
                                                    printf("Novo Agendamento confirmado\n");    
                                            }
                                           receber_id = id_cliente;// recebendo o id do cliente que vai ser reagendado
                                        }

                                        if(gerencia_agendamento == 3)// opção de cancelar agendamento do cliente
                                        {
                                            int id_cliente = 0;

                                            printf("Digite o ID no cliente\n");
                                            scanf("%d", &id_cliente);

                                            while(id_cliente == 0)
                                            {
                                                scanf("%d", &id_cliente);
                                            }

                                            for(int id = 1; id < 50; id++)
                                             {

                                                 if(id_cliente == id)
                                                 {
                                                    if(id_cliente == 1)
                                                    {
                                                        id_cliente = 0;
                                                    }
                                                        else
                                                        {
                                                             id_cliente = id-1;
                                                        }
                                                 }
                                             }
                                           pedido_por_cliente = 0;
                                           novo_total_clientes =  Remover(id_cliente,seat_chose, &pd);//funçaõ de remover Pedido

                                            if(novo_total_clientes < 0)
                                            {
                                                novo_total_clientes = 0;
                                            }

                                             agendamento_cancelado += 1;
                                             printf("Agendamento cancelado\n");
                                        }

                                        if(gerencia_agendamento == 4){ sair = 0; break;}


                                   }
                               } 
                                     

                                if(exister_cliente == 0)// se não ouver cliente
                                {
                                     printf("Sem Clientes!\n");
                                }

                            }
                        }

                        if(existe_barbeiro == 0)// se não existir usuário ou usuário for inválido
                        {
                            printf("Usuário inválido\n");
                        }

                        break;
                    }

                    sair = 0;
                    
                }

    }

    return 0;
}



void escolherHorario(int escolher_horario_certo,const char HORAS[22][30], struct Pedido *pd, int id_cliente) // função de escolher horário
{

     switch(escolher_horario_certo)
     {
         case 1:
             strcpy(pd->hora[id_cliente], HORAS[0]);
         break;
         case 2:
             strcpy(pd->hora[id_cliente], HORAS[1]);
         break;
         case 3:
             strcpy(pd->hora[id_cliente], HORAS[2]);
         break;
         case 4:
             strcpy(pd->hora[id_cliente], HORAS[3]);
         break;
         case 5:
             strcpy(pd->hora[id_cliente], HORAS[4]);
         break;
         case 6:
             strcpy(pd->hora[id_cliente], HORAS[5]);
         break;
         case 7:
             strcpy(pd->hora[id_cliente], HORAS[6]);
         break;                                   
         case 8:
             strcpy(pd->hora[id_cliente], HORAS[7]);
         break;
         case 9:
             strcpy(pd->hora[id_cliente], HORAS[8]);
         break;
         case 10:
             strcpy(pd->hora[id_cliente], HORAS[9]);
         break;
         case 11:
             strcpy(pd->hora[id_cliente], HORAS[10]);
         break;
         case 12:
             strcpy(pd->hora[id_cliente], HORAS[11]);
         break;
         case 13:
             strcpy(pd->hora[id_cliente], HORAS[12]);
         break;
         case 14:
             strcpy(pd->hora[id_cliente], HORAS[13]);
         break;                                   
         case 15:
             strcpy(pd->hora[id_cliente], HORAS[14]);
         break;
         case 16:
             strcpy(pd->hora[id_cliente], HORAS[15]);
         break;
         case 17:
             strcpy(pd->hora[id_cliente], HORAS[16]);
         break;
         case 18:
             strcpy(pd->hora[id_cliente], HORAS[17]);
         break;
         case 19:
             strcpy(pd->hora[id_cliente], HORAS[18]);
         break;                                         
     }
     
}


void escolherDia(int escolher_dia,const char DIAS[7][30], struct Pedido *pd, int id_cliente)// função de escolher dia
{

switch(escolher_dia)
{
    case 1:
        strcpy(pd->dia[id_cliente], DIAS[0]);
    break;
    case 2:
        strcpy(pd->dia[id_cliente], DIAS[1]);
    break;
    case 3:
        strcpy(pd->dia[id_cliente], DIAS[2]);
    break;
    case 4:
        strcpy(pd->dia[id_cliente], DIAS[3]);
    break;
    case 5:
        strcpy(pd->dia[id_cliente], DIAS[4]);
    break;
    case 6:
        strcpy(pd->dia[id_cliente], DIAS[5]);
    break;
    case 7:
        strcpy(pd->dia[id_cliente], DIAS[6]);
    break;                                   
} 

}

int Remover(int id_cliente,int seat_chose[50], struct Pedido *pd)// função de remover Pedido
{
    for(int id = id_cliente; id < 50; id++)
    {
        strcpy(pd->cliente[id], pd->cliente[id + 1]);
        strcpy(pd->corte[id], pd->corte[id + 1]);
        strcpy(pd->dia[id], pd->dia[id + 1]);
        strcpy(pd->hora[id], pd->hora[id + 1]);
        strcpy(pd->pagamento[id], pd->pagamento[id + 1]);
        seat_chose[id] = seat_chose[id + 1];
    }

    return id_cliente -= 1;
    
}

int verificarHorarioEscolhido(int escolher_horario, const char HORAS[22][30], int seat_chose[50])
{
    
     for(int j = 0; j < 19; j++)// sistema de verificar sé o horário já foi escolhido
     {

         if(escolher_horario == seat_chose[j])// se tiver sido escolhido
         {
             printf("Esse horário já foi escolhido\n");
             printf("Escolhar novo horário:\n");
             scanf("%d", &escolher_horario);
             while(getchar() != '\n');

                 while(escolher_horario > 19 || escolher_horario == 0 || escolher_horario == seat_chose[j])//validando horários
                 {
                     for(int time = 0; time < 19; time++)
                     {
                         printf("%d %s\n",time+1, HORAS[time]);
                     }

                     printf("Por favor escolhar um horário que estejá na lista:\n");
                     scanf("%d", &escolher_horario);
                     while(getchar() != '\n');
                 }
                 
                 return escolher_horario;

         }
     }
     
}