#importando as bibliotecas
import streamlit as st
import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt


st.sidebar.title('Menu')
selecionar_pagina = st.sidebar.selectbox('Escolha a opção: ', ['Pagina inicial','Algoritmo JumpSearch', 'Graficos'])

if selecionar_pagina == 'Pagina inicial':
    st.title('Busca De Strings utilizando JumpSearch')
    selecionar = st.selectbox('Selecione o tipo de busca que deseja: ',['Matricular alunos','Listar alunos','Buscar aluno por nome', 'Buscar aluno por matricula'])
    if selecionar == 'Matricular alunos':
        with st.form(key='Aluno'):
            input_name = st.text_input(label='Nome do aluno')
            input_matricula = st.number_input(label='Número da matricula', format= '%d', step=1)
            input_documento = st.number_input(label='Número do documento', format='%d', step=1)
            input_enviar = st.form_submit_button('Enviar')
    if selecionar == 'Listar alunos':
        df = pd.read_csv('c:\\Users\\Moises\\OneDrive\\Área de Trabalho\\Jump\\JumpSearch\\Jumpsearch.py\\data\\aluno.csv')
        st.subheader('Lista de alunos matriculados:')
        st.write('Nome: ', input_name)
    if selecionar == 'Buscar aluno por nome':
        with st.form(key='Aluno'):
            input_name = st.text_input(label='Nome do aluno')
            input_enviar = st.form_submit_button('Buscar')
    if selecionar == 'Buscar aluno por matricula':
        with st.form(key='Aluno'):
            input_matricula = st.number_input(label='Número da matricula', format= '%d', step=1)
            input_enviar = st.form_submit_button('Buscar')
    if input_enviar:
        st.write(f'Nome: {input_name}')
        st.write(f'Matricula: {input_matricula}')
        st.write(f'Documento: {input_documento}')
elif selecionar_pagina == 'Algoritmo JumpSearch':
    st.title('Codigos')
elif selecionar_pagina == 'Graficos':
    n = np.arange(0, 1000, 1)

    Tn_linear = n
    Tn_log = np.log2(n)
    Tn_jump = np.sqrt(n)

    print('Demonstrando complexidade de tempo do algoritmo JumpSearch')
    plt.plot(Tn_jump, label='raiz')
    plt.xlabel('Tamanho da entrada')
    plt.ylabel('Operações da CPU')
    plt.title('Complexidade JumpSearch')
    plt.legend()
    plt.grid()

    st.pyplot(plt)
    plt.clf()

    plt.plot(Tn_linear, label='Linear')
    plt.plot(Tn_jump, label='raiz')
    plt.plot(Tn_log, label='Log')
    plt.xlabel('Tamanho da entrada')
    plt.ylabel('Operações da CPU')
    plt.title('Comparando complexidades')
    plt.legend()
    plt.grid()

    st.pyplot(plt)
    plt.clf()