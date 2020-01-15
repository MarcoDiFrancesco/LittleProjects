from cms.toolbar_base import CMSToolbar
from cms.toolbar_pool import toolbar_pool
from polls.models import Poll

class PollToolbar(CMSToolbar):

    def populate(self):
        self.toolbar.get_or_create_menu(
            'polls_cms_integration-polls',  # a unique key for this menu
            'Polls',                        # the text that should appear in the menu
        )
