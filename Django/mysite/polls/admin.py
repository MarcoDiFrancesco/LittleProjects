"""
Amdin configuration file
"""
from django.contrib import admin

from .models import Question, Choice


class ChoiceList(admin.TabularInline):
    """
    Add choices at the end of the Question add page
    """
    model = Choice
    extra = 0


class QuestionAdmin(admin.ModelAdmin):
    """
    Admin page managing the questions
    """
    fieldsets = [
        (
            None,
            {
                'fields': ['question_text']
            }
        ),
        (
            'Date',
            {
                'fields': ['pub_date'],
                'classes': ['collapse']
            }
        ),
    ]
    inlines = [ChoiceList]

    list_display = (
        'question_text',
        'pub_date',
        'was_published_recently'
    )

    list_filter = [
        'pub_date'
    ]

    search_fields = [
        'question_textbase_site.html'
    ]

admin.site.register(Question, QuestionAdmin)
admin.site.register(Choice)
