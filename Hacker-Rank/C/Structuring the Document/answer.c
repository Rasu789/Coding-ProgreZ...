#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

struct document get_document(char* text) {
    struct document doc;
    struct paragraph* paragraphs = NULL;
    int p_idx = 0;

    char* p_saveptr;
    char* p_token = strtok_r(text, "\n", &p_saveptr);

    while (p_token != NULL) {
        paragraphs = realloc(paragraphs, (p_idx + 1) * sizeof(struct paragraph));
        struct sentence* sentences = NULL;
        int s_idx = 0;

        char* s_saveptr;
        char* s_token = strtok_r(p_token, ".", &s_saveptr);
        while (s_token != NULL) {
            sentences = realloc(sentences, (s_idx + 1) * sizeof(struct sentence));
            struct word* words = NULL;
            int w_idx = 0;

            char* w_saveptr;
            char* w_token = strtok_r(s_token, " ", &w_saveptr);
            while (w_token != NULL) {
                words = realloc(words, (w_idx + 1) * sizeof(struct word));
                words[w_idx].data = strdup(w_token);
                w_idx++;
                w_token = strtok_r(NULL, " ", &w_saveptr);
            }
            sentences[s_idx].data = words;
            sentences[s_idx].word_count = w_idx;
            s_idx++;
            s_token = strtok_r(NULL, ".", &s_saveptr);
        }
        paragraphs[p_idx].data = sentences;
        paragraphs[p_idx].sentence_count = s_idx;
        p_idx++;
        p_token = strtok_r(NULL, "\n", &p_saveptr);
    }
    doc.data = paragraphs;
    doc.paragraph_count = p_idx;
    return doc;
}



void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
