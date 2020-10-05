from django.db import models
from django.utils import timezone


class Question(models.Model):
    """
    Question model
    """

    question_text = models.CharField(max_length=200)
    pub_date = models.DateTimeField('date published')

    def __str__(self):
        return str(self.question_text)

    def was_published_recently(self):
        """
        Check if the question was pubblished in the last day
        """

        now = timezone.now()
        if(self.pub_date + timezone.timedelta(days=1) < now or self.pub_date > now):
            return False
        return True
    was_published_recently.admin_order_field = 'pub_date'
    was_published_recently.boolean = True
    was_published_recently.short_description = 'Pubblished recently?'

class Choice(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.CharField(max_length=200)
    vote = models.IntegerField(default=0)

    def __str__(self):
        return str(self.choice_text)


class Test(models.Model):
    test1 = models.IntegerField(default=0)
