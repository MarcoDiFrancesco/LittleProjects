pub struct Label {
    pub label: String,
}

impl Label {
    pub fn new(label: &str) -> Label {
        Label {
            label: label.to_owned(),
        }
    }
}

pub struct Button {
    pub label: Label,
}

impl Button {
    pub fn new(label: &str) -> Button {
        Button {
            label: Label::new(label),
        }
    }
}
